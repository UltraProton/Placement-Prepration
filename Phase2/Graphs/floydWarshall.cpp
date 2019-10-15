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
    
    return 0;
}



void floyd_warshall(vector<vector<int>> &G, int src, int dest){
    vector<vector<int>> temp=G;

    int n=G.size();

    for(int i=0;i<n;i++){
        temp[i][i]=0;
    }

    int k=n; // no of vertices

    for(int v=1;v<=k;v++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                temp[i][j]= min(temp[i][j], temp[i][k]+temp[k][j]);
            }
        }
    }
}