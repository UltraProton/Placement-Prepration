#include<bits/stdc++.h>

using namespace std;

int main(){
    int n=0;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    //Dutch national flag algorithm
    int l=0;
    int m=0;
    int r=n-1;

    /* 
    Loop invariant:
    
    1. arr[0...l-1] will be 0's
    2. arr[l...m-1] will be 1's
    3. arr[m...r] is not yet explored
    4. arr[r+1...n-1] will be 2's 

     */

    while(m<=r){
        switch(arr[m]){
            //We have got a 0 so put it at its correct position at 'l'
            case 0: swap(arr[l],arr[m]); l++; m++; break;
            // 1's can be simply ignored
            case 1: m++; break;
            //We have swapped arr[m] with arr[r] so arr[m] has reached its correct position but the element 
            //arr[r] which has just come at m is yet to be explored so 'm' will not be incremented but r will be
            // decremented because it has got 2 
            case 2: swap(arr[m], arr[r]); r--; break;
        }
    }

    for(auto x: arr){
        cout<<x<<" ";
    }


    cout<<endl;

    return 0;
}