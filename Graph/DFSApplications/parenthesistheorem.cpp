/* 

Very imp: Remember when we say that a node is visited in BFS and DFS. 

*/

#include<bits/stdc++.h>

using namespace std;

class graph
{
private:
    /* data */
    int V;
    list<int> *adj_list;

public:
    graph(int);
    ~graph();
    void add_edge(int src, int dest);
    void print_graph();

    void bfs(int src);
    void dfs(int src);
    void dfs_util(int i, int &t, vector<int> &parent,vector<int> & discovery,vector<int> &finished,vector<int> & visited);

};


int main(){
    graph g(6);

    g.add_edge(0,1);
    g.add_edge(0,2);
    g.add_edge(2,1);
    g.add_edge(1,3);
    g.add_edge(3,2);
    g.add_edge(4,3);
    g.add_edge(4,5);
    g.add_edge(5,5);


    g.print_graph();

    //g.bfs(0);

    g.dfs(0);
    
    return 0;
}


graph::graph(int n_vertices)
{
    V= n_vertices; 
    adj_list= new list<int> [V];
}

/* 

1. Destructors are important to free memory allocated during runtime by the object when the object is out of scope.

 */
graph::~graph()
{
    delete [] adj_list;
}

/* If the graph is undirected add edge only from source to destination otherwise add edge both in src adjacency list as
well as dest adjacency list */
void graph::add_edge(int src, int dest){
    adj_list[src].push_back(dest);
}

void graph::print_graph(){
    for(int i=0;i<V;i++){
        cout<<"Node "<<i<<": ";
        for(auto x:adj_list[i]){
            cout<<x<<",";
        }
        cout<<endl;
    }
}


/* You should decide when you say that a node is visited in the BFS.  */

void graph:: bfs(int src){
    /* We want to collect information from BFS so we need some memory to save it. */

    vector<int> parent(V,-1);
    vector<int> dist_from_src(V,10000);
    vector<int> visited(V,0);

    parent[src]=-1;
    dist_from_src[src]=0;
    visited[src]=1;

    queue<int> Q;
    Q.push(src);
    int curr=-1;

    while(!Q.empty()){
        curr= Q.front();
        Q.pop();
        /* Here we can't say that curr is visited */
        for(auto x:adj_list[curr]){
            /* If the node is not previously visited then insert it into the queue. */
            if(!visited[x]){
                visited[x]=1; /*Here the node was not previously seen so but now it is discovered so make it visited  */
                parent[x]=curr;
                dist_from_src[x]= dist_from_src[curr]+1;
                Q.push(x);
            }
        }
    }

    /* Let's see the result of BFS */

    for(int i=0;i<V;i++){
        cout<<"Node: "<<i<<" Parent: "<<parent[i]<<" dist from src: "<<dist_from_src[i]<<endl;
    }

}

void graph::dfs(int src){
    vector<int> parent(V,-1);
    vector<int> discovery(V,0);
    vector<int> finished(V,0);
    vector<int> visited(V,0);
    int time=0;
    /* Distance from source is not relevant here. */

    /* There are different implementations of DFS. Either you can say that visit every unvisited node of graph or 
    just run DFS only from one source 
    */

   /* Let's just run it on the every unvisited node. */

   for(int i=0;i<V;i++){
       if(!visited[i]){
            dfs_util(i,time, parent, discovery,finished, visited);
       }
   }

   // dfs_util(src,time, parent, discovery,finished, visited);

//     for(int i=0;i<V;i++){
//        cout<<"Node : "<<i<<" Parent "<<parent[i]<<" d: "<<discovery[i]<<" f: "<<finished[i]<<endl;
//    }
}

void graph::dfs_util(int src, int &t, vector<int> &parent, vector<int> &discovery, vector<int> &finished, vector<int> &visited ){
    t= t+1;
    visited[src]=1;
    discovery[src]=t;
    
    cout<<"("<<src<<" ";

    for(auto x:adj_list[src]){
        if(!visited[x]){
            parent[x]= src;
            dfs_util(x,t, parent, discovery,finished,visited);
        }
    }
    t=t+1;
    finished[src]=t;
    cout<<src<<")"<<" ";
}