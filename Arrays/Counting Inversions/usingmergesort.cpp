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
    vector<ll> L;
    vector<ll> R;
    ll ans=0;
    ll i=0,j=0;
    ll n1= mid-l+1;
    ll n2= r-mid;
    vector<ll> temp;
    
    for(int i=0;i<n1;i++){
        L.push_back(arr[l+i]);
    }

    for(int j=0;j<n2;j++){
        R.push_back(arr[j+mid+1]);
    }

    i=0;
    j=0;
    ll k=0;

    while (i<n1 && j<n2)
    {
       if(L[i] <= R[j]){
           temp.push_back(L[i]);
           i++;
       } 
       //we got the inversions
       else{
           ans=ans+ n1-i;
           temp.push_back(R[j]);
           j++;
       }
    }

    while(i<n1){
        temp.push_back(L[i]);
        i++;
    }

    while(j<n2){
        temp.push_back(R[j]);
        j++;
    }

    //copy back the elements to the input array
    k=0;
    for(i=l;i<=r;i++,k++){
        arr[i]= temp[k];
    }

    return ans;
}


