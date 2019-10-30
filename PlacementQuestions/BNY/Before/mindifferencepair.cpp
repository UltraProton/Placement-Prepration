#include<bits/stdc++.h>

using namespace std;

int max_difference(vector<int> &arr);

int main(int argc, char const *argv[])
{
    /* code */
    int t=0;
    int n=0;
    int x=0;
    vector<int> arr;
    cin>>t;
    while (t>0)
    {
        arr.clear();
        cin>>n;
        while(n>0){
            cin>>x;
            arr.emplace_back(x);
            n--;
        }

        cout<<max_difference(arr)<<endl;

        t--;
    }
    
    return 0;
}


int max_difference(vector<int> &arr){
    int ans= INT_MAX;
    sort(arr.begin(), arr.end());
    int n=arr.size();
    for(int i=0;i<n-1;i++){
        ans= min(ans, arr[i+1] -arr[i]);
    }


    return ans;



    // int ans=INT_MAX;
    // int min_ele=arr[0];
    // for(int i=1;i<arr.size();i++){
    //     min_ele= min(arr[i],min_ele);
    //     ans= min(ans,arr[i]-min_ele);
    // }

    // return ans;
}