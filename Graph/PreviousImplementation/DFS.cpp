#include<bits/stdc++.h>

using namespace std;
//Position this line where user code will be pasted.
void dfs(int s, vector<int> g[], bool vis[]);
void dfs_util(int s, vector<int> g[], bool vis);

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int N, E;
        cin>>N>>E;
        
        vector<int> g[N];
        bool vis[N];
        
        memset(vis, false, sizeof(vis));
        
        for(int i=0;i<E;i++)
        {
            int u,v;
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        dfs(0,g,vis);
        
        cout<<endl;
    }
}


/* 
Here we are running DFS on a single node.  */

void dfs(int s, vector<int> g[], bool vis[])
{   
    cout<<s<<" "; 
    vis[s]=1;
    for(auto x:g[s]){
        if(!vis[x]){
            //cout<<'x'<<endl;
            dfs(x,g,vis);
        }
    }
}





