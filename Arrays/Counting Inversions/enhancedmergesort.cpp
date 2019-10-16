#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

ll merge_sort(vector<ll> &arr, ll l, ll r);
ll merge(vector<ll> &arr, ll l, ll mid, ll r);

int main(){
    vector<ll> arr{59,29};

    int ans= merge_sort(arr,0,arr.size()-1);
    
    cout<<ans<<endl;

    return 0;
}

ll merge_sort(vector<ll> &arr, ll l, ll r){
    if(l<r){
        ll mid = l+ (r-l)/2;
        ll L_ans= merge_sort(arr, l,mid);
        ll R_ans= merge_sort(arr, mid+1,r);
        ll cross_ans= merge(arr, l,mid,r);

        return (L_ans+R_ans+cross_ans);
    }
    return 0;
}


ll merge(vector<ll> &arr, ll l, ll mid, ll r){
    // vector<ll> L;
    // vector<ll> R;
    ll ans=0;
    ll i=0,j=0;
    vector<ll> temp;
/*
    We don't even need these to count

    ll n1= mid-l+1;
    ll n2= r-mid;
    
*/    
    /*

    This temporary arrays creation and copying can be avoided but we need a temporary array

    for(int i=0;i<n1;i++){
        L.push_back(arr[l+i]);
    }

    for(int j=0;j<n2;j++){
        R.push_back(arr[j+mid+1]);
    }
    */

    i=l;
    j=mid;
    ll k=l;

    while (i<=mid-1 && j<=r)
    {
       if(arr[i] <= arr[j]){
           temp.push_back(arr[i]);
           i++;
       } 
       //we got the inversions
       else{
           ans=ans+ mid-i;
           temp.push_back(arr[j]);
           j++;
       }
    }

    while(i<=mid-1){
        temp.push_back(arr[i]);
        i++;
    }

    while(j<=r){
        temp.push_back(arr[j]);
        j++;
    }

    /*
    
    Copy back the elements to the input array. So we actually saved copying twice and the algorithm 
    is simple as well. But in the previous normal merge sort if you use L and R subarrays then this
    copying is not needed. But then that algorithm requires a lit bit of logic to not count the inversions
    which are already counted. There we will change the actual array not the temporary as we are doing here sp we
    have to be a little careful there.
    
    */

    k=0;
    for(i=l;i<=r;i++,k++){
        arr[i]= temp[k];
    }

    return ans;
}


