#include<bits/stdc++.h>

using namespace std;

int peakIndexInMountainArray(vector<int> &A);


int main(int argc, char const *argv[])
{
    vector<int> A{2,3,4,6,9,12,11,8,6,4,1};
    cout<<peakIndexInMountainArray(A)<<endl;

    return 0;
}


int peakIndexInMountainArray(vector<int> & A) {
        int l=0;
        int r=A.size()-1;
        int mid=-1;
        int ans=-1;
        while(l<=r){
            //cout<<"l= "<<l<<" r= "<<r<<endl;
            mid= l+ (r-l)/2;
            if(mid==0 || A[mid]>A[mid-1]){
                ans=mid;
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        
        return ans;
}