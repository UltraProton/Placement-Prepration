/* 
* In clrs_implementation.cpp and clrsimplementationimprovedsearch.cpp we are checking whether the element is present in the
* heap or not which is making us search the heap every time we wan't set membership.

* As we have 2 disjoint sets being grown in Prims algorithm we can instead test whether the current adjacent node is in 
* the mst set or not. 

* It will help us to only insert the vertex in the heap only when it is not yet included in the mst.

! The most important point to note here is that we can't just add the extracted node's key to the ans mst weight. Here
! we are checking for memebership of mst set and not the heap. So here same node may be inserted in the priority queue again.
! So we need to get the answer after we have traversed the tree and the information we have saved in the parent and Key
! vectors will give us the final ans. Note how the ans is constructed here. Previously in other 2 implmentations a vertex
! is inserted inside the queue only once.

* The adjacent nodes to the just added vertex are added in the priority_queue if their key is greater than the edge weight and
* they are not part of mst. So it's possible that the same vertex is inserted again in the priority queue but with lesser
* key value because of its exploration from some other vertex path. But we don't want to add those weights again and again
* we just want the minimum key edges. So this information is saved in our Key and parent vectors which don't change once
* they found the optimal ans.

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

    int n_vertices=9;

    Priority_queue Q(9);
    //To store the parent of the vertex being explored in the process
    vector<int> Parent(9,-1);
    //To store the key of every vertex in the graph
    vector<int> Key(9,10000);

    //to store whether the vertex is present in the mst set or not
    vector<int> in_mst(9,0);

    int n_vertices_in_mst=0;

    //initially we start from the source
    Q.insert_key(node(src,0));
    node curr;
    node adj;
    int w=0;
    int idx=-1;
    // * Remember the while loop condition here it iterates until the no of vertices in the mst are less than the total no of vertices
    //* As the vertex numbering starts from 0 so until all the vertices are in mst this loop runs
    while(n_vertices_in_mst<n_vertices){ // ! O(V) it runs for V vertices
        curr= Q.extract_min(); // ! O(logV)
        in_mst[curr.identity]=1; // ? This node can be included in the mst
        // *  no of vertices in mst is increased by one or we have one more vertex included in the mst
        n_vertices_in_mst+=1;

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


    cout<<"Edges of the MST: "<<endl;
    for(int i=1;i<Parent.size();i++){
        cout<<"edge: "<< i <<","<< Parent[i]<<endl;
    }

    for(int i=1;i<Key.size();i++){
        mst_weight+=Key[i];
    }

    cout<<"MST Weight: "<< mst_weight<<endl;

    return mst_weight;
}

// ! O(V*logV +  + E*V ElogV) ~ O(ElogV)


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

