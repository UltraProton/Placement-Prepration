#include<bits/stdc++.h>
#include<map>

using namespace std;

//Method 1
vector<int> method1(int *arr,int n);
vector<int> method2(int *arr, int n);
vector<int> method3(int *arr, int n);
vector<int> method4(int *arr, int n);//can only find one of the duplicates

int main(void){
    int arr[]={1,2,3,4,5,5,1,1,1,1,1,5};
    int n=sizeof(arr)/sizeof(arr[0]);
    vector<int> ans=method4(arr,n);
    for(auto x:ans)
        cout<<x<<" ";
    return 0;
}

vector<int> method1(int *arr,int n){
    map<int,int> mp;
    vector<int> ans;
    for(int i=0;i<n;i++){
        if(mp.find(arr[i])!=mp.end()){
            if(mp[arr[i]]==1){
                ans.push_back(arr[i]);
            }
            mp[arr[i]]+=1;
        }
        else
        {
                mp[arr[i]]=1;
        }
    }
    return ans;
}

/*method 1 analysis... Time: O(n) Space: O(n) can work for any range of numbers. */

vector<int> method2(int *arr, int n){
    vector<int> ans;
    for(int i=0;i<n;i++){
        if(arr[abs(arr[i]-1)]<0)
            ans.push_back(abs(arr[i]));
        else
        {
            arr[abs(arr[i]-1)]=-arr[abs(arr[i]-1)];
        }
    }
    
    return ans;
}

vector<int> method3(int *arr, int n){
    vector<int> ans;
    for(int i=0;i<n;i++){
        arr[arr[i]%n]+=n;
    }
    for(int i=0;i<n;i++){
        if(arr[i]/n > 1)
            ans.push_back(i);
    }

    return ans;
}

vector<int> method4(int *arr, int n){
    vector<int> ans;
    int s=arr[0];
    int f=arr[arr[0]];
    while(s!=f){
        s=arr[s];
        f=arr[arr[f]];
    }
    s=0;
    while(s!=f){
        s=arr[s];
        f=arr[f];
    }
    ans.push_back(s);
    return ans;
}