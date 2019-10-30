#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

ll merge_sort(vector<ll> &arr, ll l, ll r);
ll merge(vector<ll> &arr, ll l, ll r);

int main(){
    vector<ll> arr{3,2,1};

    int ans= merge_sort(arr,0,arr.size()-1);
    
    cout<<ans<<endl;

    return 0;
}

ll merge_sort(vector<ll> &arr, ll l, ll r){
    int ans=0;
    if(l<r){
        ll mid = l+ (r-l)/2;
        ans+= merge_sort(arr, l,mid);
        ans+= merge_sort(arr, mid+1,r);
        ans+= merge(arr, l,r);
    }
    return ans;
}


ll merge(vector<ll> &arr, ll l, ll r){
    // vector<ll> L;
    // vector<ll> R;
    ll ans=0;
    ll i=0,j=0;
    int mid= l + (r-l)/2;

    vector<ll> temp;

    i=l;
    j=mid+1;

    while (i<mid +1 && j<r+1)
    {
       if(arr[i] <= arr[j]){
           temp.push_back(arr[i]);
           i++;
       } 
       //we got the inversions
       else{
           ans=ans+ mid+1-i;
           temp.push_back(arr[j]);
           j++;
       }
    }

    while(i<mid+1){
        temp.push_back(arr[i]);
        i++;
    }

    while(j<r+1){
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

    ll k=0;
    for(i=l;i<=r;i++,k++){
        arr[i]= temp[k];
    }

    return ans;
}


// void mergei(int a[],int i,int j)
// {
//     int ni=((i+j)/2)+1,nj=j+1;
//     int s=i;
//     int * arr = new int [j-i+1];
//     j=ni;
//     int k=0;
//     while(i<ni && j<nj)
//     {
//         if(a[i]<=a[j])
//         {
//             arr[k]=a[i];
//             i++;
//         }
//         else
//         {
//             arr[k]=a[j];
//             ans+=(ni-i);
//             j++;
//         }
//         k++;
//     }
//     for(;i<ni;i++,k++)
//         arr[k]=a[i];
//     for(;j<nj;j++,k++)
//         arr[k]=a[j];
//     for(k=0;s<nj;s++,k++)
//         a[s]=arr[k];
//     delete [] arr;
// }

// void m_sort(int a[],int i,int j)
// {
//     if(i<j)
//     {
//         m_sort(a,i,(i+j)/2);
//         m_sort(a,((i+j)/2)+1,j);
//         mergei(a,i,j);
//     }
// }
// int main()
// {
//     int t;
//     scanf("%d",&t);
//     while(t--)
//     {
//         int n;
//         ans=0;
//         scanf("%d",&n);
//         int * a = new int[n];
//         for(int i=0;i<n;i++)
//             scanf("%d",&a[i]);
//         m_sort(a,0,n-1);
//         cout<<ans<<endl;
//     }
//     return 0;
// }