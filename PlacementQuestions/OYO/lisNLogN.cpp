#include<bits/stdc++.h>

using namespace std;

int lis(vector<int> &arr);
int low_bound(vector<int> &arr, int l, int r, int key);

int main(){

}

int lis(vector<int> &arr){
    int n=arr.size();
    vector<int> temp(n,0);
    
}

int low_bound(vector<int> &arr, int l, int r, int key){
    int m=0;
    int ans=-1;
    while(l<=r){
        m=l+(r-l)/2;
        if(arr[m]>=key){
            ans=m;
            r=m-1;
        }
        else{
            l=m+1;
        }
    }

    return ans;
}