/* 
Cycle detection in undirected graph: In undirected graphs, either Breadth First Search or Depth First Search 
can be used to detect cycle. In directed graph, only depth first search can be used. 

*/


#include <bits/stdc++.h>
using namespace std;

enum COLOR{white, gray, black};

bool isCyclic(int V, vector<int> adj[]);
bool dfs_util(vector<int> *adj, int v, vector<int> &color);

int main() {
	
	int t;
	cin >> t;
	
	while(t--){
	    
	    int v, e;
	    cin >> v >> e;
	    
	    vector<int> adj[v];
	    
	    for(int i =0;i<e;i++){
	        int u, v;
	        cin >> u >> v;
	        adj[u].push_back(v);
	    }
	    
	    cout << isCyclic(v, adj) << endl;
	    
	}
	
	return 0;
}

/*This is a function problem.You only need to complete the function given below*/
/*  Function to check if the given graph contains cycle
*   V: number of vertices
*   adj[]: representation of graph
*/


bool isCyclic(int V, vector<int> adj[])
{
    
    vector<int> color(V,white);/* Every vertex is white initially */
    

    for(int i=0;i<V;i++){
       if(color[i]==white){
           /* If the ith vertex is not yet explored then explore it and find if there is any cycle present */
            if(dfs_util(adj,i,color)){
                return true;
            } 
        }
    }
   
   return false;
}


bool dfs_util(vector<int> *adj, int v,vector<int> &color ){
    color[v]=gray;/* The current vertex is discovered or visited*/
    
    for(auto x:adj[v]){
        /* x is finished or completely explored so we don't care about it. */
        if(color[x]==black){
            continue;
        }
        /* We have found a backward edge to an ancestor. */
        if(color[x]==gray){
            return true;
        }

        /* So the only possibility is that the vertex is white i.e not yet explored so explore x and find if cycle exists
        while exploring x */

        /* If I find a cycle then call previous to me have found cycle. So returning true to them stop those calls
        from further exploring.
         */
        if(dfs_util(adj, x,color)){
            return true;
        }
    }

    /* We are done exploring v. */
    color[v]=black;
    /* We could not find a cycle so return false. */
    return false;
}

