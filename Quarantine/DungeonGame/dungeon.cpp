#include<bits/stdc++.h>
using namespace std;


int dungeon(vector<vector<int>> &grid);

int main(){
    int t=0;
    int m=0;
    int n=0;
    cin>>m>>n;
    vector<vector<int>> grid(m,vector<int>(n,0));
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>grid[i][j];
        }
    }
    
    return 0;
    
}

int dungeon(vector<vector<int>> &dungeon){
    int m=dungeon.size();
    int n=dungeon[0].size();
    vector<vector<int>> dp(m+1,vector<int>(n+1,INT_MAX));
    dp[m-1][n]=1;
    dp[m][n-1]=1;
    int x=0;
    for(int i=m-1;i>=0;i--){
        for(int j=n-1;j>=0;j--){
            x=min(dp[i+1][j],dp[i][j+1])-dungeon[i][j];
            dp[i][j]= (x<0)?(1):(x);
        }
    }

    return dp[0][0];
}