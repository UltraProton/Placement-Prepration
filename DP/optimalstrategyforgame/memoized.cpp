/* 

https://practice.geeksforgeeks.org/problems/optimal-strategy-for-a-game/0

 */

#include<bits/stdc++.h>

using namespace std;

int optimal_strategy(vector<int> &arr, int l, int r,vector<vector<int>> &memo);

int main(int argc, char const *argv[])
{
    /* code */
    int t=0;
    int n=0;
    int x=0;
    vector<int> S;
    vector<vector<int>> memo;
    cin>>t;
    int i=0;
    while(t>0){
        cin>>n;
        i=n;
        S.clear();
        while(i>0){
            cin>>x;
            S.emplace_back(x);
            i--;
        }

        memo=vector<vector<int>>(n+2,vector<int>(n+2,-1));

        cout<<optimal_strategy(S,0,S.size()-1,memo)<<endl;

        // for(auto vec: memo){
        //     for(auto ele: vec){
        //         cout<<ele<<" ";
        //     }
        //     cout<<endl;
        // }

        t--;
    }
    return 0;
}

int optimal_strategy(vector<int> &arr, int l, int r, vector<vector<int>> &memo){
    //* If there are 1 or zero elements then the solution is not possible there should be atleast 2 elements for the game to proceed
    if(l>=r){
        return 0;
    }

    //* If we have already found the solution then don't compute it and return the solution already present
    if(memo[l][r]!=-1){
        return memo[l][r];
    }

    //* If there is only one element then return it
    if(r-l==1){
        memo[l][r]=max(arr[l], arr[r]);;
        return memo[l][r];
    }

    else{
        int a=arr[l];
        int b=arr[r];

        //* Adversary will try to take maximum and want our sum to be minimum 
        //* Case 1: Take element at 'l' in which case adversary will either choose the element at l+1 or r so we will have to
        //* take min from the the 2 choices left to us. First: l+2 to r if adversary choosed l+1. Second: l+1 to r-1 if adversary
        //* chooses element at r
        a+=min(optimal_strategy(arr,l+2,r,memo),optimal_strategy(arr,l+1,r-1,memo));

        //* Case 2: I choose element at r. So again we have 2 choices after adversary takes one of the 2 choices he had. 
        //* If he chooses element at l then we will have choice of l+1 to r-1.
        //* If he chooses element at r-1 then I will have choice from l to r-2 to choose from.
        b+=min(optimal_strategy(arr, l+1,r-1, memo), optimal_strategy(arr,l,r-2,memo));

        // ? The important thing to note is that we will be forced to choose from the min of the choices the adversay takes.

        //* To win we wan't the max of the 2 choices we take
        memo[l][r]= max(a,b); 

        //? So we want to maximize the minimum we can have. 
        //! Similar to what we did in egg dropping puzzle where we want to minimize the worst case no of tries we want to identify
        //! the threshold floor

        return memo[l][r];
    }
}