#include<bits/stdc++.h>

using namespace std;

int main(){
    int t=0,n=0;
    cin>>t;
    while (t>0)
    {
        cin>>n;
        vector<int> arr(n,0);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }

        //Algorithm
        vector<int> L_max(n,0);
        int p=arr[0];
        int ans=-1;
        L_max[0]=p;
        for(int i=1;i<n;i++){
            L_max[i]=p;
            p=max(p,arr[i]);
        }
        p=arr[n-1];
        for(int i=n-2;i>=1;i--){
            if(L_max[i]<=arr[i] && p>=arr[i]){
                ans=i;
            }
            p=min(arr[i],p);
        }

        if(ans!=-1)
            cout<<arr[ans]<<endl;
        
        else{
            cout<<-1<<endl;
        }

        t--;
    }

    return 0;
    
}