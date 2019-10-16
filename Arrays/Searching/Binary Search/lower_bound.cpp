/*

Problem: Find the smallest value that is not smaller than x in an array.

1. lower_bound() : First value which does not compare less than x in the range.
2. upper_bound() : First value in the range that is greater than x. 

*/


#include<bits/stdc++.h>

using namespace std;

int my_lower_bound(vector<int> &v, int x);

int main(){
    vector<int> v{2,3,5,6,8,10,12};

    cout<<my_lower_bound(v,3)<<endl;
    cout<<*(std::upper_bound(v.begin(), v.end(),3))<<endl;
    
    return 0;
}

int my_lower_bound(vector<int> &v, int x){
    int l=0;
    int r=v.size()-1;
    int mid=0;
    int ans=-1;
    while (l<=r)
    {
        mid= l + (r-l)/2;

        if(v[mid]>=x){
            ans= v[mid];
            r=mid-1;
        }
        else{
            l=mid+1;
        }   
    }
    
    return ans;
}