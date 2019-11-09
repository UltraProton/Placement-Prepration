#include<bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n=0;
    cin>>n;
    int *dp= new int[n+1];

    dp[0]=1;
    dp[1]=0;
    dp[2]=1;

    for(int i=3;i<=n;i++){
        dp[i]= dp[i]+ (i-1)*(dp[i-1]+dp[i-2]);
    }

    cout<<dp[n]<<endl;

    return 0;
}
