#include<bits/stdc++.h>

using namespace std;

int lbs(vector<int> &arr);

int main(){
    int t=0,n=0;
    cin>>t;
    while(t>0){
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        cout<<lbs(arr)<<endl;
        t--;
    }
    return 0;
}

int lbs(vector<int> &arr){
    int n=arr.size();
    vector<int> dp1(n,1);
    vector<int> dp2(n,1);
    int ans=1;
    //Computes longest increasing subsequence ending at the index j
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[j]>arr[i] && dp1[i]+1 > dp1[j]){
                dp1[j]=dp1[i]+1;
            }
        }
    }

    //To compute longest bitonic subsequence we need to compute the longest decreasing subsequence starting at the
    //index so that at every index we have the value of the longest increasing subsequence ending at the index and
    //lds starting at the index. To compute lds therefore we will have to move from right to left

    for(int j=n-2;j>=0;j--){
        for(int i=n-1;i>j;i--){
            if(arr[j]>arr[i] && dp2[i]+1 > dp2[j]){
                dp2[j]=dp2[i]+1;
            }
        }
    }

    for(int i=0;i<n;i++){
        ans=max(ans,(dp1[i]+dp2[i]-1));
    }

    for(auto x:dp1){
        cout<<x<<" ";
    }
    cout<<endl;
    for(auto x:dp2){
        cout<<x<<" ";
    }
    cout<<endl;

    return ans;
}