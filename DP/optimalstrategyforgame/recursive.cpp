#include<bits/stdc++.h>

using namespace std;

int optimal_strategy(vector<int> &arr, int l, int r);

int main(int argc, char const *argv[])
{
    /* code */
    int t=0;
    int n=0;
    int x=0;
    vector<int> S;
    cin>>t;
    while(t>0){
        cin>>n;
        S.clear();
        while(n>0){
            cin>>x;
            S.emplace_back(x);
            n--;
        }

        cout<<optimal_strategy(S,0,S.size()-1)<<endl;

        t--;
    }
    return 0;
}

int optimal_strategy(vector<int> &arr, int l, int r){
    if(l>=r){
        return 0;
    }
    if(r-l==1){
        return max(arr[l], arr[r]);
    }
    else{
        int a=arr[l];
        int b=arr[r];

        a+=min(optimal_strategy(arr,l+2,r),optimal_strategy(arr,l+1,r-1));
        b+=min(optimal_strategy(arr, l+1,r-1), optimal_strategy(arr,l,r-2));

        return max(a,b);
    }
}