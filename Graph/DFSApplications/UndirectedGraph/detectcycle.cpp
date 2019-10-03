/* 

This code assumes that there are no parallel edges between any 2 vertices of the graph.

Idea: If a vertex A is already visited and the current vertex B is not the parent of A then we have come to A from some
descendant of A.

 */

#include<bits/stdc++.h>
using namespace std;

enum COLOR{white, gray, black};

bool isCyclic(int V, vector<int> adj[]);
bool dfs_util(vector<int> *adj, int v,vector<int> &parent, vector<int> &color);
bool dfs_util_second(vector<int> *adj, int v,vector<int> &parent, vector<int> &visited);


int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int V, E;
        cin>>V>>E;
        
        // array of vectors to represent graph
        vector<int> adj[V];
        
        int u, v;
        for(int i=0;i<E;i++)
        {
            cin>>u>>v;
            
            // adding edge to the graph
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        cout << isCyclic(V,adj)<<endl;
    }
}



bool isCyclic(int V, vector<int> adj[])
{
    
    vector<int> color(V,white);/* Every vertex is white initially */
    vector<int> visited(V,0);
    vector<int> parent(V,-1);

    for(int i=0;i<V;i++){
       if(color[i]==white){
           /* If the ith vertex is not yet explored then explore it and find if there is any cycle present */
            if(dfs_util_second(adj,i,parent,visited)){
                return true;
            } 
        }
    }
   
   return false;
}


/* 
Here we just need to know whether a vertex is visited or not which we are doing with the help of color[] here.
Its making sense here. There is just one if condition which checks whether the vertex is visited or not. So we can
use something like visited[] to check if the vertex is visited or not. 

Imp Note: The color vertex is extremely important in case of directed graph. But not here.

 */

bool dfs_util(vector<int> *adj, int v,vector<int> &parent, vector<int> &color ){
    color[v]=gray;/* The current vertex is discovered */
    
    for(auto x:adj[v]){
        //if the vertex is not visited i.e color is white then explore it
        if(color[x]==white){  
            parent[x]=v; //v is the parent of current vertex x
            if(dfs_util(adj, x, parent,color)){
                return true;
            }
        }

        // We have found an already visited vertex let's check if adjacent vertex x is parent of v. 
        //If it is not then we have found a cycle
        else if(parent[v] != x){
            return true;
        }
    }

    /* 
    We are done exploring v. See that below statement is not important now because we are not checking if the color is 
    black or not in our dfs_util() 
    */
    color[v]=black;
    /* We could not find a cycle so return false. */
    return false;
}



bool dfs_util_second(vector<int> *adj, int v,vector<int> &parent, vector<int> &visited){
    visited[v]=true;
    for(auto x:adj[v]){
        if(!visited[x]){
            parent[x]=v;
            if(dfs_util_second(adj, x, parent,visited)){
                return true;
            }
        }

        /* Check x is parent of v . If x is parent of v then we have a cycle */
        else if(parent[v]!=x){
            return true;
        }
    }

    /* A cycle wasn't detected */
    return false;
}



// bool dfs_util(vector<int> *adj, int v,vector<int> &parent, vector<int> &color ){
//     color[v]=gray;/* The current vertex is discovered */
    
//     cout<<v<<endl;

//     for(auto x:adj[v]){
//         /* x is finished or completely explored so we don't care about it. */
//         if(color[x]==black){
//             continue;
//         }
        
//         if(color[x]==gray && parent[v] != x){
//             return true;
//         }

//         parent[x]=v;
//         /* So the only possibility is that the vertex is white i.e not yet explored so explore x and find if cycle exists
//         while exploring x */
//         if(dfs_util(adj, x,parent,color)){
//             return true;
//         }
//     }

//     /* We are done exploring v. */
//     color[v]=black;
//     /* We could not find a cycle so return false. */
//     return false;
// }


