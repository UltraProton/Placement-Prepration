#include<bits/stdc++.h>
using namespace std;

int main(){
    int t=0;
    int n=0,m=0;
    cin>>t;
    while(t>0){
        cin>>m>>n;
        vector<int> arr1(m);
        vector<int> arr2(n);
        for(int i=0;i<m;i++){
            cin>>arr1[i];
        }
        for(int j=0;j<n;j++){
            cin>>arr2[j];
        }

        //Algorithm
        for(int i=0;i<m;i++){
            if(arr1[i]> arr2[0]){
                //pop_heap() removes the top of the heap and put it at the end of the container thereby 
                //reducing the size of the heap by one. Remember the heap size is reduced by 1 but the element
                //is still present in the container
                pop_heap(arr2.begin(), arr2.end(),greater<int>());

                //swap the last element with arr[i]
                int t=arr1[i];
                arr1[i]=arr2[n-1];
                arr2[n-1]=t;

                //To use push_heap() the element must be inserted at the back of the container which is done
                //by the above swap step
                push_heap(arr2.begin(),arr2.end(),greater<int>());
            }
        }

        sort_heap(arr2.begin(),arr2.end());

        for(auto x:arr1){
            cout<<x<<" ";
        }
        cout<<endl;
        for(auto x:arr2){
            cout<<x<<" ";
        }

        cout<<endl;

        t--;
    }
    return 0;
}