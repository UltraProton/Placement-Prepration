//Use floyd warshall to compute all the shortest distances between every pair of vertices

#include<bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    int n=0;
    cin>>n;
    vector<vector<int>> dp(n+1,vector<int>(n+1,100000));
    int w=0;
    for(int i=0;i<n;i++){
        cin>>w;
        int v=(i+1)%n;
        dp[i][v]= w;
        dp[v][i]=w;

        dp[i][i]=0;
    }

      for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }

    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(dp[i][j] > dp[i][k]+ dp[k][j]){
                    dp[i][j]= dp[i][k]+dp[k][j];
                }
            }
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}




