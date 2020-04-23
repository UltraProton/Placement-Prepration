#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

ll ms(vector<ll> &arr, ll l, ll r);
ll merge1(vector<ll> &arr, ll l, ll m, ll r);

int main(int argc, char const *argv[])
{
    /* code */
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
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

        cout<<ms(arr,0,arr.size()-1)<<endl;;

        t--;
    }
    return 0;
}


ll ms(vector<ll> &arr, ll l, ll r){
    ll ans=0;
    if(l<r){
        ll m=l+ (r-l)/2;
        ans=ms(arr,l,m);
        ans+=ms(arr,m+1,r);
        ans+=merge1(arr,l,m+1,r);
    }
    
    return ans;
}

ll merge1(vector<ll> &arr, ll l, ll m, ll r){
    vector<ll> temp;
    ll x=l;
    ll y=m;
    ll ans=0;
    while(x<m && y<=r){
        if(arr[x]<=arr[y]){
            temp.emplace_back(arr[x]);
            x++;
        }
        else{
            ans+=m-x;
            temp.emplace_back(arr[y]);
            y++;
        }
    }
    
    while(x<m){
        temp.emplace_back(arr[x]);
        x++;
    }
    
    while(y<=r){
        temp.emplace_back(arr[y]);
        y++;
    }
    
    ll  k=0;
    for(ll i=l;i<=r;i++,k++){
        arr[i]=temp[k];
    }
    
    return ans;
}






























/*

long long inversions(vector<long long> &arr, ll l, ll r){
    long long ans=0;
    if(l<r){
        
        int mid= l+(r-l)/2;
        ans+=inversions(arr,l,mid);
        ans+=inversions(arr,mid+1,r);
        ans+=merge(arr,l,mid+1,r);
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
    
    k=0;
    for(long long i=l;i<=r;i++,k++){
        arr[i]= temp[k];
    }

    return ans;
}



  */
