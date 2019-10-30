#include<bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{

    int n=0;
    cin>>n;
    
    vector<int> arr(n,0);

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }


    vector<int> dp(n,1);

    for(int i=n-2;i>=0;i--){
        for(int j=n-1;j>i;j--){
            if(arr[j] < arr[i] && dp[j]+1 > dp[i]){
                dp[i]=dp[j]+1;
            }
        }
    }

    int ans=INT_MIN;

    for(auto x: dp){
        if(ans<x){
            ans=x;
        }
    }

    cout<<ans;

    return 0;
}
