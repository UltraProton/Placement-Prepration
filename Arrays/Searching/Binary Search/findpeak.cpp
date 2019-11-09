#include<bits/stdc++.h>

using namespace std;

int find_peak(vector<int> &arr, int l , int r, int  n);

int main(int argc, char const *argv[])
{
    /* code */

    vector<int> arr{1,2};

    cout<<find_peak(arr,0,arr.size()-1,arr.size())<<endl;

    return 0;
}

int find_peak(vector<int> &arr, int l, int r, int n){
    
    int mid= l +(r-l)/2;

    //if the mid element is the peak return it
    if((mid==0 || arr[mid-1]<=arr[mid]) && (mid==n-1 ||  arr[mid]>=arr[mid+1])){
        return mid;
    }


    if(mid> 0 && arr[mid-1] > arr[mid]){
        return find_peak(arr,l,mid-1,n);
    }
    else{
        return find_peak(arr,mid+1,r,n);
    }
}