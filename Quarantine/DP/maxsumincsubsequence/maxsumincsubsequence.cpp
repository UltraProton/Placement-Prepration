#include<bits/stdc++.h>
using namespace std;

int max_sum_inc_subseq(vector<int> &arr);

int main(){
    int t=0,n=0;
    cin>>t;
    while(t>0){
        cin>>n;
        vector<int> arr(n,0);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }

        cout<<max_sum_inc_subseq(arr)<<endl;

        t--;
    }
    return 0;
}

int max_sum_inc_subseq(vector<int> &arr){
    vector<int> dp;
    dp=arr;
    int n=arr.size();
    int ans=arr[0];
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[j]>arr[i] && dp[i]+arr[j]>dp[j]){
                dp[j]=dp[i]+arr[j];
                ans=max(ans,dp[j]);
            }
        }
    }

    return ans;
}