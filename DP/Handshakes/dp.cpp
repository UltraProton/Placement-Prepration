#include<bits/stdc++.h>

using namespace std;

int handshakes(int n){
    vector<int> dp(n+1);
    dp[0]=1;
    dp[1]=1;

    for(int i=2;i<=n;i++){
        for(int j=1;j<=i;j++){
            dp[i]= dp[i]+ dp[j-1]*dp[i-j];
        }
    }

    return dp[n];
}

int main(int argc, char const *argv[])
{
    int n=0;
    cin>>n;
    
    cout<<handshakes(n)<<endl;

    return 0;
}
