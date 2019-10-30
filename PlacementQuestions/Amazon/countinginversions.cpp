#include<bits/stdc++.h>

using namespace std;

int inversions(vector<int> &arr, int l, int r);
int merge(vector<int> &arr, int l, int m, int r);

int main(int argc, char const *argv[])
{
    /* code */
    int n=0,t=0;
    cin>>t;
    while(t>0){        
        cin>>n;
        vector<int> arr;
        int x=0;
        
        for(int i=0;i<n;i++){
            cin>>x;
            arr.emplace_back(x);
        }

        cout<<inversions(arr,0,arr.size()-1)<<endl;;

        t--;
    }
    return 0;
}

int inversions(vector<int> &arr, int l, int r){
    int ans=0;
    if(l<r){
        
        int mid= l+(r-l)/2;
        ans+=inversions(arr,l,mid);
        ans+=inversions(arr,mid+1,r);
        ans+=merge(arr,l,mid+1,r);
    }

    return ans;
}


int merge(vector<int> &arr, int l, int m, int r){
    vector<int> temp;
    int ans=0;

    int x= l;
    int y=m;

    while(x<m && y<=r){
        if(arr[x]<=arr[y]){
            temp.emplace_back(arr[x]);
            x++;
        }
        else{
            ans= ans + m-x;
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

    int k=0;
    for(int i=l;i<=r;i++,k++){
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