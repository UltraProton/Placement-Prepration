#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--) {
        int k,n;
        cin>>k>>n;
        int arr[n];
        for(int i=0;i<n;i++){
        cin>>arr[i];
        }
        int ans[n+10]={0};//to print result
        int i=0,j=0;
        int sum=arr[0];
        while(i<n&&j<n){
        if(sum<=k){
            j++;
            if(j>=i){
                int len = j-i;
                ans[len+1]--;   /* updating the count of subarrays similar to this
                                 https://w...content-available-to-author-only...k.com/challenges/crush/problem*/
                ans[1]++;
            }
            if(j<n){
                sum+=arr[j];
            }
        }
        else{
             
            sum-=arr[i];
            i++;
        }
    }
    for(int i=1;i<=n;i++){
        ans[i]+=ans[i-1];
    }
    for(int i=1;i<=n;i++)
        cout<<ans[i]<<" ";
    cout<<endl;
}
}