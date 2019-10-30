#include<bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    int n,x,m;

    cin>>m>>n>>x;
    
    vector<vector<int>> dp(n+1,vector<int>(x+1,0));

    for(int i=1;i<=x && i<=m; i++){
        dp[1][i]=1;
    }

    for(int i=2;i<=n;i++){
        for(int j=1;j<=x;j++){
            for(int k=1;k<=m && k<j; k++){
                dp[i][j]+=dp[i-1][j-k];
            }
        }
    }

    cout<<dp[n][x]<<endl;

    return 0;
}
