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


//https://en.wikipedia.org/wiki/Floyd%E2%80%93Warshall_algorithm

void floyd_warshall(vector<vector<int>> &G, int src, int dest){
    int n=G.size();
    vector<vector<int>> dist(n,vector<int>(n,1000));
    vector<vector<int>>path(n,vector<int>(n,-1));

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            dist[i][j]=G[i][j];
            path[i][j]=j;
        }
    }

    for(int i=0;i<n;i++){
        dist[i][i]=0;
        path[i][i]=i;
    }

    //for each vertex in the graph
    for(int v=0;v<n;v++){
        //check if the shortest path between any pair of vertices includes vertex 'v' or not
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                //If the current distance between vertex 'i' and 'j' have larger distance than the distance we would have if we go
                //from i to v and then v to j
                if(dist[i][j]> dist[i][v]+ dist[v][j]){
                    dist[i][j]=dist[i][v]+dist[v][j]; //Then update the distance between i and j
                    path[i][j]= path[i][v]; //Save that the shortest path between vertices i and j includes v
                }
            }
        }
    }

    cout<<"Print the matrix:"<<endl;

    // for(int i=0;i<n;i++){
    //     for(int j=0;j<n;j++){
    //         cout<<dist[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<path[i][j]<<" ";
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
