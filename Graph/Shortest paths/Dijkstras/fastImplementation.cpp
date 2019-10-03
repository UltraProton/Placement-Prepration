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
    vector<int> key_index; //* stores the index of key in the storage[] of priority queue
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


   // Priority_Queue Q;

    // Q.insert_key(1,100);

    // Q.insert_key(2,10);

    // for(int i=0;i<Q.queue_size;i++){
    //     cout<<Q.storage[i].key<< "," <<Q.storage[i].distance<<endl;
    // }

    // char c ='y';

    // while(c=='y'){
    //     queue_node temp= Q.extract_min();
    //     cout<<temp.key<<" , "<<temp.distance<<endl;
    //     cin>>c;
    // }



    // for(int i=0;i<5;i++){
    //     Q.insert_key(i,10000);
    // }

    // //decrease the source distance value;
    // Q.decrease_key(0,0);



    // for(int i=0;i<Q.queue_size;i++){
    //     cout<<Q.storage[i].key<< "," <<Q.storage[i].distance<<endl;
    // }


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

    for(int i=0;i<V;i++){
        Q.insert_key(i,10000);
        indices[i]=i;
    }

    // for(int i=0;i<V;i++){
    //     cout<<Q.storage[i].key<<endl;
    // }  


    //decrease the source distance value
    //* when we insert all the keys in the queue with same distance value then they will be stored in linear order in the storage
    //* so at index 0 we will have the node which was inserted first. So we can decrease key of the source because the vertex 
    //* identifier is considered to be 0,1,2....n
    Q.decrease_key(src,0);
    dist[src]=0;

    queue_node curr;
    
    while (!Q.empty())
    {
        curr= Q.extract_min();
        processed[curr.key]=1; //* The current vertex has the final shortest distance from the source got calculated
        for(auto v: adj[curr.key]){
            if(processed[v.first]==0 && dist[v.first]> dist[curr.key] +  v.second){
                dist[v.first]= dist[curr.key]+ v.second;
                parent[v.first]=curr.key;

                //! Who is going to make update in the heap ????

                Q.decrease_key(Q.key_index[v.first],dist[v.first]);
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
    key_index= vector<int>(1000,-1);
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
