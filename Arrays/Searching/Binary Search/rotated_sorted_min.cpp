/* 

Observation: In this kind of array the element previous to minimum element will always be greater. Making use of this we
can write recursion.
 
 */



#include<bits/stdc++.h>

using namespace std;

int min_ele_recursive(vector<int> &V, int l,int r);
int min_ele_iterative(vector<int> &V);
void tab(int n);

int main(){

    vector<int> v{3,4,5,6,7,8,9,10,11,12,12,13,14,15,16,17,18,19,20,2};
    
    cout<<min_ele_recursive(v,0,v.size()-1)<<endl;

    cout<<min_ele_iterative(v)<<endl;

    return 0;
}

int min_ele_recursive(vector<int> &arr, int l, int r){
    cout<<"min_ele( l= "<<l<<" r= "<<r<<")"<<endl;

    //find out the test case for below check
    if(l>r){
        return arr[0];
    }
    //if array has only one element
    if(r==l){
        return arr[r];
    }

    int mid= l + (r-l)/2;

    //prev to mid is greater so we found min element at the mid
    if(l < mid && arr[mid-1] > arr[mid]){
        return arr[mid];
    }

    //next to mid is smaller than mid element so next to mid is minimum in the array
    if(r > mid  && arr[mid+1] < arr[mid]){
        return arr[mid+1];
    }
    //from mid to r the array is sorted in increasing order so there is no chance to find min element on that side
    if(arr[mid] < arr[r]){
        return min_ele_recursive(arr,l,mid-1);
    }

    //otherwise search on the right side of the array
    else{
        return min_ele_recursive(arr,mid+1,r);
    }
}


/* The iterative version is the decent one but requires some good thinking.

This link has good explanation: https://www.youtube.com/watch?v=GU7DpgHINWQ

E.g:      [ 4, 5, 6, 7, 8, 2, 3 ]               

Observations: 

1. If you see the above array then what we need to find is the boundary where the array is divided. Its between 8 and 2. The
previous element is greater for the min element. Otherwise for each element other than the min the previous element is 
smaller. 

2. We can't just go to mid and compare the left and right of mid and make some conclusion. What we can do is compare the mid
with the first element to arrive at some conclusion and based on that we can go to left or right.

 */

int min_ele_iterative(vector<int> &v){
    int l=0;
    int r= v.size()-1;
    int mid= -1;
    int ans=-1;

    while(l<=r){
        mid= l+ (r-l)/2;
        if(v[mid]>v[r]){
            l=mid+1;

        }
        else{
            ans=v[mid];
            r=mid-1;
        }
    }

    return ans;
}





void tab(int n){
    for(int i=1;i<=n;i++){
        cout<<"    ";
    }
}