/*

* Here because we are already inserting all the nodes in the heap so we need to use decrease_key(idx, key) which 
* requires at which index we wan't to update the key value. For this we need to search the heap linearly each time we
* want to update the key of adjacent node to  current node.

*In this implementation we are just using another vector for retreiving the key corresponding to a node quickly.

 */


#include<bits/stdc++.h>

using namespace std;

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
    void decrease_key(int idx, int key);
    int find(int key);
    bool empty();
    void min_heapify(int idx);
    int l_child(int idx);
    int r_child(int idx);
    int parent(int idx);
};

void print_graph(vector<vector<pair<int,int>>> &G);
void add_edge(vector<vector<pair<int,int>>> &G, int u, int v,int wt);
int Prims(vector<vector<pair<int,int>>> &G,int src);

int find_weight(vector<vector<pair<int,int>>> &G, int src, int dest){
    for(auto x:G[src]){
        if(x.first==dest){
            return x.second;
        }
    }

    return -1;
}


int main(int argc, char const *argv[])
{

    vector<vector<pair<int,int>>> G(9);

    add_edge(G,0,1,4);
    add_edge(G,0,7,8);
    add_edge(G,1,7,11);
    add_edge(G,1,2,8);
    add_edge(G,2,3,7);
    add_edge(G,2,8,2);
    add_edge(G,2,5,4);
    add_edge(G,3,4,9);
    add_edge(G,3,5,14);
    add_edge(G,4,5,10);
    add_edge(G,5,6,2);
    add_edge(G,6,8,6);
    add_edge(G,6,7,1);
    add_edge(G,7,8,7);
    
    //print_graph(G);

    Prims(G,0);

    //cout<<Prims(G,0)<<endl;
    
    return 0;
}


int Prims(vector<vector<pair<int,int>>> &G, int src){
    int ans=0;

    Priority_queue Q(9);
    //To store the parent of the vertex being explored in the process
    vector<int> Parent(9,-1);
    vector<int> Key(9,10000);

    vector<int> present_in_heap(9,1);

    //add all the nodes of the graph to the priority queue
    for(int i=0;i<9;i++){   // ! O(V)
        Q.insert_key(node(i,10000));
    }


    //update the source key to 0
    Q.decrease_key(src,0);
    node curr;
    node adj;
    int w=0;
    int idx=-1;
    while(!Q.empty()){ // ! O(V) it runs for V vertices
        curr= Q.extract_min(); // ! O(logV)
        present_in_heap[curr.identity]=0;
        cout<<curr.identity;
        ans+=curr.key;
        //for every vertex adjacent to current vertex in the graph
        for(auto x:G[curr.identity]){ // ! O(2|E|) altogether iterating over adjacency list of each vertex
            //cout<<x.first<<" ";
            /* 
            * We need to find whether x is present in the queue or not. If x is not in the queue then it must be in mstset
            * So we consider only those vertices which are not present in the mstset
            *  
            * */

            // * If the node is not in the heap then it is in the mst so continue as we don't need to explore x now 
            if(present_in_heap[x.first]==0){ // ! O(1)
                continue;
            }

            else{
                idx= Q.find(x.first); // ! O(V)

                //find the node adjacent to curr in the priority queue
                //adj=Q.storage[idx];
                //find the weight of the adjacent node from the graph
                //w= find_weight(G,curr.identity,adj.identity);
                w=x.second;
                //if the current key of the node is greater than the edge weight between current and adjacent
                if(Key[x.first] > w){
                    Key[x.first]=w;
                    //update the key of the node in the priority queue
                    Q.decrease_key(idx, w); // ! O(logV)
                    //save the parent of adjacent to current in the parent vector
                    Parent[x.first]=curr.identity;
                }    
            
            }
        }

        cout<<endl;
    }

    cout<<"Edges of the MST: "<<endl;
    for(int i=1;i<Parent.size();i++){
        cout<<"edge: "<< i <<","<< Parent[i]<<endl;
    }

    cout<<"MST Weight: "<< ans<<endl;

    return ans;
}

//! O(V*logV + V*V + E*V ElogV) ~ O(V^2)


void print_graph(vector<vector<pair<int,int>>> &G){
    int curr_vector=0;
    for(auto L:G){
        cout<<curr_vector<<" : ";
        for(auto P:L){
            cout<<"( "<<P.first<<" "<<P.second<<" )";
        }
        cout<<endl;
        curr_vector++;
    }
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


void Priority_queue :: decrease_key(int idx , int key){
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

