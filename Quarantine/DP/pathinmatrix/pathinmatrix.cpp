#include<bits/stdc++.h>

using namespace std;

int path_in_matrix(vector<vector<int>> &grid);

int main(){

}


int path_in_matrix(vector<vector<int>> &grid){
    int m=grid.size();
    int n=grid[0].size();
    //This is for my own reference:
    //In this problem note the dimensions of the dp table to avoid those if conditions involving indices to check
    //for correct indices
    vector<vector<int>> dp(m,vector<int>(n+2,0));

    for(int i=1;i<=n;i++){
        dp[0][i]=grid[0][i-1];
    }

    for(int i=1;i<m;i++){
        for(int j=1;j<=n;j++){
            dp[i][j]=max(dp[i-1][j],max(dp[i-1][j-1],dp[i-1][j+1]))+ grid[i][j-1];
        }
    }

    int ans=0;
    for(int i=1;i<=n;i++){
        ans=max(ans,dp[m-1][i]);
    }

    return ans;
}
