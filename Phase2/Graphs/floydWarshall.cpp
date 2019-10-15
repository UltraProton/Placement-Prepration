#include<bits/stdc++.h>

using namespace std;

void floyd_warshall(vector<vector<int>> &G, int src, int dest);

int main(int argc, char const *argv[])
{
    /* code */
    vector<vector<int>> G(3,vector<int>(3,1000));

    G[0][1]=2;
    G[1][2]=5;
    G[2][0]=-1;

    for(auto vec: G){
        for(auto ele: vec){
            cout<<ele<<" ";
        }
        cout<<endl;
    }


    floyd_warshall(G,0,2);
    
    return 0;
}



void floyd_warshall(vector<vector<int>> &G, int src, int dest){
    int n=G.size();
    vector<vector<int>> dist(n,vector<int>(n,10000));
    vector<vector<int>>path(n,vector<int>(n,-1));
    
    for(int i=0;i<n;i++){
        dist[i][i]=0;
        path[i][i]=i;
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            dist[i][j]=G[i][j];
            path[i][j]=j;
        }
    }



    int k=n; // no of vertices

    for(int v=1;v<=k;v++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(dist[i][j]> dist[i][k]+ dist[k][j]){
                    dist[i][j]=dist[i][k]+dist[k][j];
                    path[i][j]= path[i][k];
                }
            }
        }
    }

    cout<<"Print the matrix:"<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<dist[i][j]<<" ";
        }
        cout<<endl;
    }


    if(path[src][dest]!=-1){
        cout<<src<<" ";
        while(src!=dest){
            src=path[src][dest];
            cout<<src<<" ";
        }
    }
}