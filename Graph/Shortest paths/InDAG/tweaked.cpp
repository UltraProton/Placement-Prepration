/* 
* Its better to make topological_order[] as part of class. So I will change the code like that.

 */


#include<bits/stdc++.h>

using namespace std;

// class edge{
//     public:
//     int u;
//     int v;
//     int wt;
//     edge(int u, int v, int wt);
// };

class Graph{
    public:
    int V;
    vector<int> parent;
    vector<int> dist;
    vector<vector<pair<int,int>>> adj;
    Graph(int n_vertices);
    //void relax(int u, int v);
    vector<int> topological_order;
    void add_edge(int u, int v, int wt);
    void topological_sort();
    void topological_sort_helper(int src, vector<int> &Visited);
    void shortest_path(int src);
    void print_Graph();
};

int main(int argc, char const *argv[])
{
    Graph G(6);
    G.add_edge(0,1,5);
    G.add_edge(0,2,3);
    G.add_edge(1,2,2);
    G.add_edge(1,3,6);
    G.add_edge(2,3,7);
    G.add_edge(2,4,4);
    G.add_edge(2,5,2);
    G.add_edge(3,4,-1);
    G.add_edge(3,5,1);
    G.add_edge(4,5,-2);

    G.shortest_path(1);

    //G.print_Graph();

    //G.topological_sort();

    // for(auto x:G.topological_order){
    //     cout<<x<<endl;
    // }

    return 0;
}

// edge:: edge(int u, int v, int wt){
//     this->u=u;
//     this->v=v;
//     this->wt=wt;
// }

Graph :: Graph(int n_vertices){
    V=n_vertices;
    adj= vector<vector<pair<int,int>>>(V); //* Giving memory to V vertices of the graph in the adjacency list
}

void Graph :: add_edge(int u ,int v, int wt){
    adj[u].emplace_back(make_pair(v,wt));
}

void Graph :: shortest_path(int src){
    //* Topologically sort the vertices 
    topological_sort();

    //* Initialize single source s
    parent= vector<int>(V,-1);
    dist=vector<int>(V,10000);//? If I had initialized dist[] with INT_MAX then while relaxing we will have INT_MAX + something
                              //? which will be integer overflow condition and we will get some negative value

    dist[src]=0;

    //cout<<topological_order[0]<<endl;

    //* for each vertex u taken in topologically sorted order
    for(auto x:topological_order){
        //* for each vertex v belongs to G.adj[u] 
        for(auto y : adj[x]){
            //* relax(u,v)
            //relax(x, y.first);
            if(dist[y.first] > dist[x] + y.second){
                dist[y.first]= dist[x]+ y.second;
                parent[y.first]=x;
            }
        }
    }

    for(int i=0;i<V;i++){
        cout<<i<<","<<parent[i]<<", "<<dist[i]<<endl;
    }

}

void Graph :: topological_sort(){
    //* topological sort is same as dfs
    vector<int> Visited(V,0);
    for(int i=0;i<V;i++){
        if(!Visited[i]){
            topological_sort_helper(i,Visited);
        }
    }

    //* We are pushing the elements at the back of the topological_order in each recursive call so the most recent visited vertex
    //* "v" will be pushed at the back after processing all the adjacent vertex to "v" which is exactly opposite to the topological
    //* order we want to have so we need to reverse it to get the original topological order
    reverse(topological_order.begin(), topological_order.end());
}

void Graph :: topological_sort_helper(int src, vector<int> &Visited){
    Visited[src]=1;
    for(auto x:adj[src]){
        if(!Visited[x.first]){
            topological_sort_helper(x.first,Visited);
        }
    }

    topological_order.emplace_back(src);
}

void Graph :: print_Graph(){
    int i=0;
    for(auto vec:adj){
        cout<<i;
        for(auto pr: vec){
            cout<<" "<<pr.first<<","<<pr.second<<" ";
        }

        i++;
        cout<<endl;
    }
}


// void Graph ::relax(int u , int v){
// }



