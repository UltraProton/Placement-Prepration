#include<bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    vector<int> arr;

    int n=0;

    cin>>n;
    int x=0;

    // { 8, 58, 71, 18, 31, 32, 63, 92, 43, 3, 91, 93, 25, 80, 28 };

    for(int i=0;i<n;i++){
        cin>>x;
        arr.emplace_back(x);
    }

    //Find the next greater for each element
    for(int i=0;i<n;i++){
        int ng=INT_MAX;
        for(int j=i+1;j<n;j++){
            if(arr[j]> arr[i] && arr[j] < ng ){
                ng=arr[j];
            }
        }
        if(ng==INT_MAX){
            arr[i]=-1;
        }
        else{
            arr[i]=ng;
        }
    }

    for(auto x: arr){
        cout<<x<<" ";
    }
    cout<<endl;

    return 0;
}
