#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

long long inversions(vector<ll> &arr, ll l, ll r);
long long merge(vector<ll> &arr, ll l, ll m, ll r);

int main(int argc, char const *argv[])
{
    /* code */
    ll n=0,t=0;
    cin>>t;
    while(t>0){        
        cin>>n;
        vector<long long> arr;
        long long x=0;
        
        for(long long i=0;i<n;i++){
            cin>>x;
            arr.emplace_back(x);
        }

        cout<<inversions(arr,0,arr.size()-1)<<endl;;

        t--;
    }
    return 0;
}

long long inversions(vector<long long> &arr, ll l, ll r){
    long long ans=0;
    if(l<r){
        
        int mid= l+(r-l)/2;
        ans+=inversions(arr,l,mid);
        ans+=inversions(arr,mid+1,r);
        ans+=merge(arr,l,mid+1,r);

        //return ans;
    }

    return ans;
}


long long merge(vector<ll> &arr, ll l, ll m, ll r){
    ll *temp= new ll[r-l+1];
    
    long long ans=0;

    long long x= l;
    long long y=m;
    ll k=0;
    while(x<m && y<=r){
        if(arr[x]<=arr[y]){
            temp[k++]= (arr[x]);
            x++;
        }
        else{
            ans= ans + m-x;
            temp[k++]=(arr[y]);
            y++;
        }
    }

    while(x<m){
        temp[k++]=(arr[x]);
        x++;
    }

    while(y<=r){
        temp[k++]=(arr[y]);
        y++;
    }

    //long long k=0;
    k=0;
    for(long long i=l;i<=r;i++,k++){
        arr[i]= temp[k];
    }

    return ans;
}
