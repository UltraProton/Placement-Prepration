//https://www.hackerrank.com/challenges/primsmstsub/problem


#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

//node to be inserted in the priority queue
class node{
    public:
    int key;
    int identity;
    //default constructor
    node(){};
    node(int identity, int key);
};

class Priority_queue{
    public:
    int Q_size;
    vector<node> storage;
    node NIL;
    Priority_queue(int n);
    void insert_key(node n);
    node extract_min();
    void update_key(int idx, int key);
    int find(int key);
    bool empty();
    void min_heapify(int idx);
    int l_child(int idx);
    int r_child(int idx);
    int parent(int idx);
};

void print_graph(vector<vector<pair<int,int>>> &G);
void add_edge(vector<vector<pair<int,int>>> &G, int u, int v,int wt);

// Complete the prims function below.
int prims(int n, vector<vector<int>> edges, int start) {

    int ans=0;


    /* Take the input as a graph*/

    vector<vector<pair<int,int>>> G(3005);

    for(auto edge:edges){
        add_edge(G,edge[0],edge[1],edge[2]);
    }

    Priority_queue Q(3005);
    //To store the parent of the vertex being explored in the process
    vector<int> Parent(3005,-1);
    //To store the key of every vertex in the graph
    vector<int> Key(3005,INT_MAX);

    //to store whether the vertex is present in the mst set or not
    vector<int> in_mst(3005,0);

    //initially we start from the source
    Q.insert_key(node(start,0));
    node curr;
    node adj;
    int w=0;
    int idx=-1;
    while(!Q.empty()){ // ! O(V) it runs for V vertices
        curr= Q.extract_min(); // ! O(logV)
        in_mst[curr.identity]=1; // ? This node can be included in the mst
        cout<<curr.identity;
        //for every vertex adjacent to current vertex in the graph
        for(auto x:G[curr.identity]){ // ! O(2|E|) all together which is the size of the adjacency list
            
           // weight of the adjacent edge 
           w=x.second;

           // if x is not in the mst and its key is greater than the edge weight between curr and x then we can explore it 
           if(in_mst[x.first]==0 && Key[x.first] > w){

                Key[x.first]=w;
                //save the parent of adjacent to current in the parent vector
                Parent[x.first]=curr.identity;
                //insert the node in the priority queue
                Q.insert_key(node(x.first,Key[x.first])); //! O(logE)                   
            } 
        }

        cout<<endl;
    }

    
    int mst_weight=0;


    
    for(int i=1;i<=n;i++){
        if(i==start){
            continue;
        }
        mst_weight+=Key[i];
    }

    cout<<"MST Weight: "<< mst_weight<<endl;

    return mst_weight;


}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

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

    int start;
    cin >> start;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int result = prims(n, edges, start);

    fout << result << "\n";

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



node :: node(int identity, int key){
    this->key=key;
    this->identity=identity;
}

Priority_queue :: Priority_queue(int n){
    Q_size=0;
    
    // * Here we are giving memory to storage and each location has a node but remember we need default constructor here.
    //* when we say node below then we are actually calling the default constructor of this node but if we don't define
    // * the default constructor and we have a parameterized constructor then it will say candidate expects some arguments
    // * but zero provided
    storage= vector<node>(n);
    NIL= node(-1,-1);
}


void Priority_queue :: insert_key(node n){
    storage[Q_size]= n;
    Q_size++;

    int idx=Q_size-1;
    
    while(idx>0 &&  storage[idx].key < storage[parent(idx)].key ){
        swap(storage[parent(idx)], storage[idx]);
        idx=parent(idx);
    }
}


void Priority_queue :: update_key(int idx , int key){
    storage[idx].key=key;
    while(idx > 0 && storage[parent(idx)].key > storage[idx].key){
        swap(storage[parent(idx)], storage[idx]);
        idx=parent(idx);
    }
}

bool Priority_queue :: empty(){
    return Q_size==0;
}

node Priority_queue :: extract_min(){
    if(Q_size==0){
        cout<<"Queue is empty"<<endl;
        return NIL;
    }

    node ans=storage[0];
    swap(storage[0], storage[Q_size-1]);
    Q_size--;

    min_heapify(0);

    return ans;
}

void Priority_queue :: min_heapify(int idx){

    if(idx>=Q_size){
        return;
    }

    int l_idx= l_child(idx);
    int r_idx = r_child(idx);
    int smallest_idx= idx;
    
    if(l_idx < Q_size && storage[l_idx].key < storage[smallest_idx].key){
        smallest_idx=l_idx;
    }

    if(r_idx < Q_size && storage[r_idx].key < storage[smallest_idx].key){
        smallest_idx=r_idx;
    }

    if(smallest_idx != idx){
        swap(storage[smallest_idx], storage[idx]);
        min_heapify(smallest_idx);
    }
}


// Return the index of the node to be found
int Priority_queue :: find(int identity){
    for(int idx=0;idx<Q_size;idx++){
        if(storage[idx].identity==identity){
            return idx;
        }
    }

    return -1;
}

int Priority_queue :: parent(int idx){
    return (idx-1)/2;
}

int Priority_queue :: l_child(int idx){
    return 2*idx+1;
}

int Priority_queue :: r_child(int idx){
    return 2*idx+2;
}

void add_edge(vector<vector<pair<int,int>>> &G, int u, int v,int wt){
    G[u].push_back(make_pair(v,wt));
    G[v].push_back(make_pair(u,wt));
}

