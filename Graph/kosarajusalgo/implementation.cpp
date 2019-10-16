/* 

https://practice.geeksforgeeks.org/problems/strongly-connected-components-kosarajus-algo/1

 */

#include<bits/stdc++.h>

using namespace std;

#include<bits/stdc++.h>
using namespace std;
//Position this line where user code will be pasted.

int kosaraju(int V, vector<int> adj[]);

void dfs(int src, vector<vector<int>> &adj, stack<int> &st, vector<int> &visited);

int main()
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int a,b ;
   	    cin>>a>>b;
   	    int m,n;
   	    vector<int> adj[a+1];
        for(int i=0;i<b;i++){
            cin>>m>>n;
            adj[m].push_back(n);
        }
        // exit(0);
        cout<<kosaraju(a, adj)<<endl;
    }
    return 0;
}



void dfs(int src, vector<vector<int>> &adj, stack<int> &st, vector<int> &visited){
    visited[src]=1;
    for(auto v: adj[src]){
        if(visited[v]==0){
            dfs(v,adj,st,visited);
        }
    }

    st.push(src);
}

int kosaraju(int V, vector<int> adj[]){
    vector<vector<int>> G(V);
    stack<int> st;
    vector<int> visited(V,0);

    for(int i=0;i<V;i++){
        G[i]= (adj[i]);
    }

    //* Call dfs on the graph
    for(int i=0;i<V;i++){
        if(!visited[i]){
            dfs(i,G,st,visited);
        }
    }

    //* Take the transpose of the graph 
    //? Clearing each vector of 2d graph is important simply G.clear() won't work
    for(int i=0;i<V;i++){
        G[i].clear();
    }
    //* Taking transpose here
    for(int i=0;i<V;i++){
        for(auto ele: adj[i]){
            G[ele].emplace_back(i);
        }
    }

    int curr=0;

    stack<int> temp_st;
    visited= vector<int>(V,0);

    int count=0;

    while(!st.empty()){
        curr=st.top();
        st.pop();
        if(!visited[curr]){
            dfs(curr,G,temp_st,visited);
            count++;
        }
    }

    return count;

    // for(int i=0;i<V;i++){
    //     cout<<i<<" : ";
    //     for(auto ele: adj[i]){
    //         cout<<ele<<" ";
    //     }
    //     cout<<endl;
    // }

    // cout<<endl<<endl;

    // for(int i=0;i<V;i++){
    //     cout<<i<<" : ";
    //     for(auto ele: G[i]){
    //         cout<<ele<<" ";
    //     }
    //     cout<<endl;
    // }

}
