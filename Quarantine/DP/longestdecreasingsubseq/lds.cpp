#include<bits/stdc++.h>

using namespace std;

int lds(vector<int> &arr);

int main(){
    vector<int> arr{1,2,0,5,3,1,0};
    cout<<lds(arr)<<endl;
    return 0;
}

int lds(vector<int> &arr){
    int n=arr.size();
    vector<int> dp(n,1);
    int ans=1;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[i] && dp[i]+1 > dp[j]){
                dp[j]=dp[i]+1;
                ans=max(ans,dp[j]);
            }
        }
    }

    return ans;
}