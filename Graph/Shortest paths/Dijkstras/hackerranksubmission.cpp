/* https://www.hackerrank.com/challenges/dijkstrashortreach/problem

* Note that the graph here is undirected

 */

#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// This node will be used in queue
class queue_node{
    public:
    int key; // The node identifier
    int distance; // The shortest distance of the node from the source
    queue_node(){}; //! Default constructor is important because when we are giving memory to vector<queue_node> storage in the 
                    //! Priority queue default constructor will be called
    queue_node(int k, int d);
};


class Priority_Queue{
    public:
    int queue_size;
    vector<queue_node> storage;
    vector<int> key_index;
    queue_node extract_min();
    bool empty();
    int l_child(int idx);
    int r_child(int idx);
    int parent(int idx);
    void decrease_key(int idx, int key);
    void insert_key(int k, int d);
    void min_heapify(int idx);
    Priority_Queue();
};

class Graph{
    public:
    int V;
    Graph(int n_vertices);
    void add_edge(int u, int v, int wt);
    vector<vector<pair<int,int>>> adj;
    void Dijkstra(int src, vector<int> &dist);
    void print_graph();
};



// Complete the shortestReach function below.
vector<int> shortestReach(int n, vector<vector<int>> edges, int s) {
    Graph G(n+1);

    vector<int> dist(n+1, 1000000);

    for(auto edge: edges){
        G.add_edge(edge[0],edge[1],edge[2]);
    }

    // for(int i=1;i<=n;i++){
    //     cout<<i<<":";
    //     for(auto pr:G.adj[i]){
    //         cout<<pr.first<<","<<pr.second<<" ";
    //     }
    //     cout<<endl;
    // }

    G.Dijkstra(s,dist);

    // for(int i=2;i<=n;i++){
        
    //     cout<<dist[i]<<" ";
    // }

    vector<int> ans;
    for(int i=1;i<=n;i++){
        if(i!=s){
            cout<<dist[i]<<" ";
            ans.emplace_back(dist[i]);
        }
    }

    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string nm_temp;
        getline(cin, nm_temp);

        vector<string> nm = split_string(nm_temp);

        int n = stoi(nm[0]);

        int m = stoi(nm[1]);

        vector<vector<int>> edges(m);
        for (int i = 0; i < m; i++) {
            edges[i].resize(3);

            for (int j = 0; j < 3; j++) {
                cin >> edges[i][j];
            }

            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        int s;
        cin >> s;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        vector<int> result = shortestReach(n, edges, s);

        for (int i = 0; i < result.size(); i++) {
            fout << result[i];

            if (i != result.size() - 1) {
                fout << " ";
            }
        }

        fout << "\n";
    }

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}


Graph :: Graph(int n_vertices){
    V=n_vertices;
    adj= vector<vector<pair<int,int>>>(V); // Giving memory to the graph for storing pairs in their adjaceny list
}

void Graph :: add_edge(int u, int v, int wt){
    adj[u].emplace_back(make_pair(v,wt));
    adj[v].emplace_back(make_pair(u,wt));
}

void Graph :: Dijkstra(int src, vector<int> &dist){
    //cout<<"n_vertices: "<<V<<endl;
    vector<int> parent(V,-1);
    vector<int> processed(V,0);
    Priority_Queue Q;// To store the nodes in the priority queue

    for(int i=1;i<V;i++){
        Q.insert_key(i,1000000);
    }



    // for(int i=0;i<Q.queue_size;i++){
    //     cout<<Q.storage[i].key<<" "<<Q.storage[i].distance<<endl;
    // }  


    //decrease the source distance value
    //* when we insert all the keys in the queue with same distance value then they will be stored in linear order in the storage
    //* so at index 0 we will have the node which was inserted first. So we can decrease key of the source because the vertex 
    //* identifier is considered to be 1,2....n

    Q.decrease_key(src-1,0);
    dist[src]=0;

    // for(int i=0;i<Q.queue_size;i++){
    //     cout<<Q.storage[i].key<<" "<<Q.storage[i].distance<<endl;
    // }  

    queue_node curr;
    
    while (!Q.empty())
    {
        curr= Q.extract_min();
        //cout<<curr.key<<endl;
        processed[curr.key]=1;
        for(auto v: adj[curr.key]){
            if(processed[v.first]==0 && dist[curr.key]!=1000000 &&  dist[v.first]> dist[curr.key] +  v.second ){
                dist[v.first]= dist[curr.key]+ v.second;
                parent[v.first]=curr.key;

                //! update the distance value of v in the heap
                // for(int i=0;i<Q.queue_size;i++){
                //     if(Q.storage[i].key==v.first){
                //         Q.decrease_key(i,dist[v.first]);
                //     }
                // }

                Q.decrease_key(Q.key_index[v.first],dist[v.first]);
            }
        }
    }

    //* If the parent of a vertex is -1 then it is not reachable from the source
    for(int i=1;i<V;i++){
        if(parent[i]==-1){
            dist[i]=-1;
        }
    }  

}




Priority_Queue :: Priority_Queue(){
    queue_size=0;
    // Giving the max size to queue
    storage= vector<queue_node>(3500);
    key_index= vector<int>(3500,-1);
}

bool Priority_Queue :: empty(){
    return queue_size==0;
}

void Priority_Queue :: insert_key(int k , int d){
    storage[queue_size]=queue_node(k,d);
    key_index[k]= queue_size;
    queue_size++;
    int idx=queue_size-1;
    while(idx > 0 && storage[idx].distance < storage[parent(idx)].distance){
        swap(key_index[storage[idx].key], key_index[storage[parent(idx)].key]);
        swap(storage[idx], storage[parent(idx)]);
        idx=parent(idx);
    }
}

void Priority_Queue :: decrease_key(int idx, int dist){
    storage[idx].distance=dist;
    while (idx > 0 && storage[idx].distance < storage[parent(idx)].distance)
    {

        swap(key_index[storage[idx].key], key_index[storage[parent(idx)].key]);
        
        swap(storage[idx], storage[parent(idx)]);

        idx=parent(idx);
    }
}

queue_node Priority_Queue :: extract_min(){
    
    if(queue_size==0){
        cout<<"Queue is empty"<<endl;
        return queue_node(-1,-1);
    }


    queue_node ans= storage[0];
    swap(key_index[storage[0].key], key_index[storage[queue_size-1].key]);
    key_index[storage[0].key]=-1;
    swap(storage[0], storage[queue_size-1]);
    queue_size--;
    min_heapify(0);

    return ans;
}

void Priority_Queue :: min_heapify(int idx){
    int l_idx= l_child(idx);
    int r_idx= r_child(idx);
    int smallest_idx= idx;

    if(l_idx < queue_size && storage[l_idx].distance < storage[smallest_idx].distance){
        smallest_idx=l_idx;
    }

    if(r_idx < queue_size && storage[r_idx].distance < storage[smallest_idx].distance){
        smallest_idx=r_idx;
    }

    if(smallest_idx != idx){

        swap(key_index[storage[smallest_idx].key], key_index[storage[idx].key]);
        swap(storage[smallest_idx], storage[idx]);
        min_heapify(smallest_idx);
    }
}

int Priority_Queue :: l_child(int idx){
    return (2*idx+1);
}

int Priority_Queue :: r_child(int idx){
    return (2*idx+2);
}

int Priority_Queue :: parent(int idx){
    return (idx-1)/2;
}


queue_node::queue_node(int k, int d){
    key=k;
    distance=d;
}

