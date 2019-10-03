/* 

Great article: https://medium.com/swlh/dynamic-programming-minimum-jumps-from-start-finish-b2943afe4a72

 */


#include<bits/stdc++.h>

using namespace std;

int min_jumps(vector<int> &arr, int i, int n);

int main(int argc, char const *argv[])
{
    /* code */
    vector<int> V;
    int t=0,n=0,x=0;
    cin>>t;

    while(t>0){
        V.clear();
        cin>>n;
        while(n>0){
            cin>>x;
            V.emplace_back(x);
            n--;
        }

        // for(auto ele: V){
        //     cout<<ele<<" ";
        // }
        int ans=INT_MAX;
        cout<<min_jumps(V, 0, V.size()-1)<<endl;

        t--;
    }
    return 0;
}

int min_jumps(vector<int> &arr, int l, int r){
    //* If I am at index l=r then we don't need any steps to reach r as we are already there
    if(l==r){
        return 0;
    }

    //* When nothing is reachable from source then we have no of jumps as infinity to reach any node like we do in 
    //* Dijkstra's algorithm (when we are not reachable to a vertex from the source then its distance from source is infinity
    if(arr[l]==0){
        return INT_MAX;
    }


    else{
        int ans= INT_MAX;
        //* for each possibility of jump from the current position in the array
        //* The condition second condition in and is important because from a position l we can go upto position l+arr[l]
        //* forward by taking at max arr[l] steps from l
        for(int k=l+1;k<=r && k <= l +arr[l];k++){
            //cout<<'x'<<endl;
            int jumps= min_jumps(arr,k,r); //* Get the ans of starting at 'k' then 
            if(jumps!=INT_MAX && jumps + 1 < ans ){//* If the no of jumps from k to r is not infinity (INT_MAX) then we can reach
                                                   //* to 'r' from 'k' and we would need 1 more jump to reach to k from l and if
                                                   //* jumps+1 is less than the ans we already have then ans= jumps+1
                ans=jumps+1;
            }
        }

        return ans;
    }
}