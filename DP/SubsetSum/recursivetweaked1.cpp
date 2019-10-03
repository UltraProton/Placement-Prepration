/* Exploring the subset from right to left in recursive we explored the input from left to right.

 */


#include<bits/stdc++.h>

using namespace std;

bool subset_sum(vector<int> &S, int curr_idx, int target_sum );

int main(int argc, char const *argv[])
{
    //vector<int> S{1,2,3};

    vector<int> S{3, 34, 4, 12, 5, 2};
    

    cout<<subset_sum(S,S.size(),9)<<endl;

    return 0;
}

bool subset_sum(vector<int> &S , int curr_idx, int target_sum){
    //if the target sum is negative then no solution is possible
    if(target_sum<0){
        return false;
    }

    //if target sum is 0 then only one solution is possible empty set {}
    if(target_sum==0){
        return true;
    }

    //if we reach out of index and still target is more than zero then we don't have a solution
    if(curr_idx<=0 && target_sum > 0){
        return false;
    }
    
    else{
        //2 choices
        return (
            subset_sum(S,curr_idx-1,target_sum-S[curr_idx-1])  || //either including the current set element in the subset gives us solution 
            subset_sum(S,curr_idx-1,target_sum)); // or not including the current set element in the subset gives the solution
    }
}