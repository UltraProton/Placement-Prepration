#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

ll inversions(ll *arr, ll l, ll r);
ll merge(ll *arr, ll l, ll m, ll r);

int main(int argc, char const *argv[])
{
    /* code */
    ll n=0,t=0;
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
    
    cin>>t;
    while(t>0){        
        cin>>n;
        ll *arr= new ll[n];
        long long x=0;
        
        for(long long i=0;i<n;i++){
            cin>>x;
            arr[i]=x;
        }

        cout<<inversions(arr,0,n-1)<<endl;
        t--;
    }
    return 0;
}

long long inversions(ll *arr, ll l, ll r){
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


long long merge(ll *arr, ll l, ll m, ll r){
    ll *temp= new ll[r-l+1];
    
    long long ans=0;

    long long x= l;
    long long y=m;
    ll k=0;
    while(x<=m-1 && y<=r){
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

    while(x<=m-1){
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

    delete [] temp;
    
    return ans;
}
