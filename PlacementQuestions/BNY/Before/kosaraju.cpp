/* Kosaraju algo is used for finding stronly connected component in directed graph. For undirected we can simply run dfs on the graph for
every unvisited vertex.
 */

#include<bits/stdc++.h>

using namespace std;

void topo_sort(vector<vector<int>> &G,vector<int> &visited, vector<int> &result, int src);
void kosaraju(vector<vector<int>> &G);

int main(int argc, char const *argv[])
{
    /* code */
    vector<vector<int>> G(5);
    G[0].emplace_back(2);
    G[0].emplace_back(3);
    G[1].emplace_back(0);
    G[2].emplace_back(1);
    G[3].emplace_back(4);

    /* Graph g(5); 
    g.addEdge(1, 0); 
    g.addEdge(0, 2); 
    g.addEdge(2, 1); 
    g.addEdge(0, 3); 
    g.addEdge(3, 4); 
   */

    kosaraju(G);

    return 0;
}

void kosaraju(vector<vector<int>> &G){
    int n=G.size();
    vector<int> visited(n,0);
    vector<int> result;

    for(int i=0;i<n;i++){
        if(!visited[i]){
            topo_sort(G,visited,result,i);
            cout<<endl;
        }
    }

    // for(auto x: result){
    //     cout<<x<<" ";
    // }

    //Take the transpose of the graph

    vector<vector<int>> T_G(n);

    for(int i=0;i<n;i++){
        for(auto u:G[i]){
            T_G[u].emplace_back(i);
        }
    }

    cout<<endl;

    // for(int i=0;i<n;i++){
    //     cout<<i<<": ";
    //     for(auto v:T_G[i]){
    //         cout<<v<<",";
    //     }
    //     cout<<endl;
    // }

    //Run DFS on that in the order of topological sort and count the no of strongly connected components
    int count=0;
    fill(visited.begin(), visited.end(),0);
    vector<int> temp_result;
    for(auto v: result){
        if(!visited[v]){
            count++;
            topo_sort(T_G, visited,result,v);
            cout<<endl;
        }
    }

    cout<<count<<endl;
}

void topo_sort(vector<vector<int>> &G,vector<int> &visited, vector<int> &result, int src){
    visited[src]=1;
    for(auto v: G[src]){
        if(!visited[v]){
            topo_sort(G,visited,result,v);
        }
    }
    cout<<src<<" ";
    result.emplace_back(src);
}

