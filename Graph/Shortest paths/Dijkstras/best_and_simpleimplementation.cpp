/* 
* We can't have prim's fastimplemenation.cpp kind of optimization here. Because when we change the distance in dist[] we also need
* to change the distance of the vertex in the priority_queue. So we need to maintain some kind of index according to the vertices
* which stores at which index in the priority queue the vertex "v" is stored.
 */

#include<bits/stdc++.h>

using namespace std;

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
    void Dijkstra(int src);
};



int main(int argc, char const *argv[])
{
    /* code */

    Graph G(5);

    G.add_edge(0,1,10);
    G.add_edge(0,2,5);
    G.add_edge(1,2,2);
    G.add_edge(1,3,1);
    G.add_edge(2,1,3);
    G.add_edge(2,3,9);
    G.add_edge(2,4,2);
    G.add_edge(3,4,4);
    G.add_edge(4,3,6);

    G.Dijkstra(0);

    return 0;
}


Graph :: Graph(int n_vertices){
    V=n_vertices;
    adj= vector<vector<pair<int,int>>>(V); // Giving memory to the graph for storing pairs in their adjaceny list
}

void Graph :: add_edge(int u, int v, int wt){
    adj[u].emplace_back(make_pair(v,wt));
}

void Graph :: Dijkstra(int src){
    vector<int> dist(V,10000);
    vector<int> parent(V,-1);
    vector<int> processed(V,0);
    vector<int> indices(V,-1);

    Priority_Queue Q;// To store the nodes in the priority queue


    dist[src]=0;

    queue_node curr;

    Q.insert_key(src,dist[src]);
    
    while (!Q.empty())
    {
        curr= Q.extract_min();
        processed[curr.key]=1; //* The current vertex has the final shortest distance from the source got calculated
        for(auto v: adj[curr.key]){
            if(processed[v.first]==0 && dist[v.first]> dist[curr.key] +  v.second){
                dist[v.first]= dist[curr.key]+ v.second;
                parent[v.first]=curr.key;

                Q.insert_key(v.first, dist[v.first]);
                
            }
        }
    }

    for(int i=0;i<V;i++){
        cout<<i<<" , "<<dist[i]<< " , "<<parent[i]<<endl;
    }  
  
}





Priority_Queue :: Priority_Queue(){
    queue_size=0;
    // Giving the max size to queue
    storage= vector<queue_node>(1000);
}

bool Priority_Queue :: empty(){
    return queue_size==0;
}

void Priority_Queue :: insert_key(int k , int d){
    storage[queue_size]=queue_node(k,d);
    queue_size++;
    int idx=queue_size-1;
    while(idx > 0 && storage[idx].distance < storage[parent(idx)].distance){
        swap(storage[idx], storage[parent(idx)]);
        idx=parent(idx);
    }
}

void Priority_Queue :: decrease_key(int idx, int dist){
    storage[idx].distance=dist;
    while (idx > 0 && storage[idx].distance < storage[parent(idx)].distance)
    {
        
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
