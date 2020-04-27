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

        //Algorithm1
        int key=0;
        int j=0;
        //for each element in the second array
        // for(int i=n-1;i>=0;i--){
            //store the last element of the first array
        //     int last=arr1[m-1];
            //Find the smallest element which is greater than  
        //     for(j=m-2;j>=0 && arr1[j]>arr2[i]; j--){
        //         arr1[j+1]=arr1[j];
        //     }

        //     if(j!=m-2 || last>key){
        //         arr1[j+1]=arr2[i];
        //         arr2[i]=last;
        //     }
        // }

        //Algorithm 2
        for(int i=n-1;i>=0;i--){
            key=arr2[i];
            j=m-1;
            if(arr1[j]>key){
                //swap the values
                arr2[i]=arr2[i]^arr1[j];
                arr1[j]=arr2[i]^arr1[j];
                arr2[i]=arr2[i]^arr1[j];

                //insertion sort logic
                j=j-1;
                while(j>=0 && arr1[j]>key){
                    arr1[j+1]=arr1[j];
                    j--;
                }

                arr1[j+1]=key;
            }
        }



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