#include<bits/stdc++.h>

using namespace std;
//Position this line where user code will be pasted.

void bfs(int s, vector<int> adj[], bool vis[], int N);

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        
        int N, E;
        cin>>N>>E;
        vector<int> adj[N];
        bool vis[N] = {false};
        
        for(int i=0;i<E;i++)
        {
            int u,v;
            cin>>u>>v;
            adj[u].push_back(v);
        }
        
        bfs(0, adj, vis, N);
        cout<<endl;
    }
}

/*This is a function problem.You only need to complete the function given below*/
/* You have to complete this function*/
/* Function to do BFS of graph
*  adj[]: array of vectors
*  vis[]: array to keep track of visited nodes
*/
void bfs(int s, vector<int> adj[], bool vis[], int N)
{
    // Your code here
    list<int> Q;
    Q.push_back(s);
    int curr= -1;
    while(!Q.empty()){
        curr = Q.front();
        Q.pop_front();

        if(!vis[curr]){
            vis[curr]=1; /* curr was not visited but now it is discovered.  */
            cout<<curr<<" ";
                        
            for(auto x:adj[curr]){
                Q.push_back(x);
            }
        }
    }
}