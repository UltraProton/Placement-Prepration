#include<bits/stdc++.h>
using namespace std;
//Position this line where user code will be pasted.
/*  Function to check if elements returned by user 
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/


void dfs(int v, vector<int> *adj, stack<int> &st,vector<int> &visited);
int* topoSort(int V, vector<int> adj[]);

//int *ans;

bool check(int V, int* res, vector<int> adj[]){
    bool flag =true;
    for(int i=0;i<V && flag;i++)
    {
        int n=adj[res[i]].size();
        for(auto j : adj[res[i]])
        {
            for(int k=i+1;k<V;k++)
            {
                if(res[k]==j )
                    n--;
            }
        }
        if(n!=0)
            flag =false;
    }
    if(flag==false)
        return 0;
    return 1;
}
// Driver Code
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int N,E;
        cin>>E>>N;
        int u,v;
        
        vector<int> adj[N];
        
        for(int i=0;i<E;i++)
        {
            cin>>u>>v;
            adj[u].push_back(v);
        }
    
        int *res = topoSort(N, adj);
        
        cout<<check(N, res, adj)<<endl;
       
    }
}



int* topoSort(int V, vector<int> adj[])
{
    static int ans[50];
    
    vector<int> visited(V,0);
    stack<int> st;

    for (int i = 0; i < V; i++)
    {
        if(!visited[i]){
            dfs(i,adj,st,visited);
        }
        
    }

    int i=0;
    
    while(!st.empty()){
        ans[i]= st.top();
        //cout<<st.top()<<" ";
        st.pop();
        i++;
    }

    //cout<<"x"<<endl;

    return ans;  
}

// * Remember we need visited array in this
void dfs(int v, vector<int> *adj, stack<int> &st,vector<int> &visited){
    visited[v]=1; //* Here the vertex is visited
    for(auto x:adj[v]){
        if(!visited[x]){
            dfs(x,adj, st, visited);
        }
    }
    
    //* push the current vertex into the stack
    //* The current vertex will be pushed into the stack when all the vertices on the directed path are pushed into stack in DFS
    //* order.
    st.push(v);
}