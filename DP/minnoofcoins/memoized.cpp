/* 

https://practice.geeksforgeeks.org/problems/number-of-coins/0

! ************************************ "Can't be memoized" **************************

*/

#include<bits/stdc++.h>

using namespace std;

int min_coins(vector<int> &V, int idx, int target, vector<vector<int>> &memo);

int main(int argc, char const *argv[])
{
    /* code */
    int t=0,v=0,n=0,x=0,y=0;
    vector<int> V;
    vector<vector<int>> memo;
    cin>>t;
    while(t>0){
        cin>>v;
        cin>>n;
        y=n;

        while(y>0){
            cin>>y;
            V.emplace_back(y);
            y--;
        }
        memo= vector<vector<int>>(n+1,vector<int>(v,1000));

        cout<<min_coins(V,n,v,memo)<<endl;

        for(auto vec: memo){
            for(auto ele: vec){
                cout<<ele<<" ";
            }
            cout<<endl;
        }

        t--;
    }
    return 0;
}

int min_coins(vector<int> &V, int idx, int target, vector<vector<int>> &memo){
    // if(target == 0){
    //     memo[idx][target]=0;
    //     return 0;
    // }    

     

    if(target <= 0){
        return 0;
    }

    if(idx<=0 && target > 0){
        return INT_MAX;
    }

    // if(target==0){
    //     return 1;//* Dont make any change
    // }

    if(memo[idx][target]!=1000){
        return memo[idx][target];
    }

   


    else{

          memo[idx][target]=min(min_coins(V,idx-1,target,memo), 1+min_coins(V,idx-1,target-V[idx-1],memo));

          return memo[idx][target];
    }
}
