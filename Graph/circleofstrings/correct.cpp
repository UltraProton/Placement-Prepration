/* 


! In geeks they say that we should find whether there is an euler circuit present here or not. But this submission got AC in
! there portal

* Just identifying whether the graph has cycle won't solve this problem. The cycle may not include every vertex. There may be cycle
* in the graph involving subset of vertices. Example test case: 

1
4
ccaae deddb bc eaacc
0 : 3 
1 : 2 
2 : 0 
3 : 0 

* In the above test case we have a cycle between strings at 0 and 3 but it doesn't involve all the strings.

* To solve this problem we should identify whether the graph has a single strongly connected component or not in which case there
* will be path between any 2 vertices i.e every vertex will be reachable from any other vertex.

 */


#include<bits/stdc++.h>

using namespace std;

bool circle_possible(vector<string> &V);
int kosaraju(vector<vector<int>> &G);
void dfs(vector<vector<int>> &G, int src, vector<int> & visited, stack<int> &st);

int main(int argc, char const *argv[])
{
    /* code */
    vector<string> V;
    int t=0;
    int n=0;
    string x;
    cin>>t;
    while(t>0){
        V.clear();
        cin>>n;
        while(n>0){
            cin>>x;
            V.emplace_back(x);
            n--;
        }

        cout<<(circle_possible(V))<<endl;

        t--;
    }
    return 0;
}

bool circle_possible(vector<string> &V){
    int n=V.size();

    //* If we have only one string then the ans is 1
    if(n==1){
        if(*(V[0].begin())==*(V[0].end()-1)){
            return 1;
        }
        else{
            return 0;
        }
    }

    if(n==1 && V[0].size()==1){
        return 1;
    }

    else if(n==1 && V[0].size()>1){
        return 0;
    }

    vector<int> color(n,'w');

    vector<vector<int>> G(n);//* Creating a graph

    for(int i=0;i<n;i++){
        for(int j=0;j<n ;j++){
            if(j!=i){
                if(*(V[i].end()-1)==*(V[j].begin())){
                    G[i].emplace_back(j);
                }
            }
        }
    }

    // for(int i=0;i<n;i++){
    //     cout<<i<<" : ";
    //     for(auto ele: G[i]){
    //         cout<<ele<<" ";
    //     }
    //     cout<<endl;
    // }

    
    return kosaraju(G)==1;
}

int kosaraju(vector<vector<int>> &G){
    int n=G.size();
    
    vector<int> visited(n,0);
    stack<int> st;

    for(int i=0;i<n;i++){
        if(!visited[i]){
            dfs(G,i,visited,st);
        }
    }

    vector<vector<int>> G_T(n); // To store the transpose of the graph

    for(int i=0;i<n;i++){
        for(auto ele: G[i]){
            G_T[ele].emplace_back(i);
        }
    }

    visited= vector<int>(n,0);
    stack<int> temp_st;
    int curr=-1;
    int count=0;

    while(!st.empty()){
        curr=st.top();
        st.pop();
        if(!visited[curr]){
            dfs(G_T,curr,visited,temp_st);
            count++;
        }
    }


    // for(int i=0;i<n;i++){
    //     cout<<i<<" : ";
    //     for(auto ele :G[i]){
    //         cout<<ele<<" "; 
    //     }
    //     cout<<endl;
    // }

    // cout<<"\n\n";

    // for(int i=0;i<n;i++){
    //     cout<<i<<": ";
    //     for(auto ele :G_T[i]){
    //         cout<<ele<<" "; 
    //     }
    //     cout<<endl;
    // }




    return count;
}


void dfs(vector<vector<int>> &G, int src, vector<int> &visited, stack<int> &st){
    visited[src]=1;
    
    for(auto v : G[src]){
        if(!visited[v]){
            dfs(G,v,visited,st);
        }
    }
    
    st.push(src);
}