/* https://practice.geeksforgeeks.org/problems/perfect-sum-problem/0 

? In this problem constraint' are not correct

*/

#include<bits/stdc++.h>

using namespace std;

int perfect_sum(vector<int> &S, int curr_idx, int target_sum);

int main(int argc, char const *argv[])
{
    vector<int> S{2, 3, 5, 6, 8, 10};

    cout<< perfect_sum(S,S.size(),10)<<endl;

    return 0;
}

int perfect_sum(vector<int> &S, int curr_idx, int target_sum){
    // negative target sum can't have a solution
    if(target_sum < 0){
        return 0;
    }
    
    //empty set is the solution in this case
    if(target_sum==0){
        return 1;
    }

    // * if we have traversed the whole set and still the target sum is positive then we could not find the solution
    if(curr_idx<=0 && target_sum>0){
        return 0;
    }

    else{
        return (perfect_sum(S,curr_idx-1,target_sum) + perfect_sum(S,curr_idx-1, target_sum-S[curr_idx-1]));
    }

}
