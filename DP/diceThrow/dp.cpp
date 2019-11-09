#include<bits/stdc++.h>

using namespace std;

int dicethrow(int n,int x,int m);

int main(int argc, char const *argv[])
{
    int t=0;
    int n=0;
    int m=0;
    int x=0;
    int ans=0;

    cin>>t;

    while (t>0)
    {   
        cin>>n;
        cin>>x;
        cin>>m;

        int dp[n+1][x+1];
        memset(dp,0,sizeof(dp));

        for(int i=1;i<=m && i<=x;i++){
            dp[1][i]=1;
        }

        //for each dice
        for(int i=2;i<=n;i++){
            //for each value of sum from 1 till x
            for(int j=1;j<=x;j++){
                //find the value of dp[i][j] for each possible value on the dice
                for(int k=1;k<=m && k<j;k++){ //k<j check is important so that we don't access invalid memory
                    dp[i][j]+=dp[i-1][j-k];
                }
            }
        }

        cout<<dp[n][x]<<endl;

        t--;
    }
    

    return 0;
}

