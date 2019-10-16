/* 

Given a set of non-negative integers, and a value sum, determine if there is a subset of the given set with sum equal to given sum.

Example:

Input:  set[] = {3, 34, 4, 12, 5, 2}, sum = 9
Output:  True  //There is a subset (4, 5) with sum 9.

 */

#include<bits/stdc++.h>

using namespace std;

bool subset_sum(vector<int> &S,int target_sum);
bool subset_sum_helper(vector<int> &S, vector<int> &curr_subset, int set_idx, int target_sum);
int vector_sum(vector<int> & V);

int main(int argc, char const *argv[])
{
    vector<int> S{3, 34, 4, 12, 5, 2};

    cout<<subset_sum(S,9)<<endl;

    return 0;
}

bool subset_sum(vector<int> &S, int target_sum){
    vector<int> curr_subset;
    return subset_sum_helper(S,curr_subset,0,target_sum);
}

bool subset_sum_helper(vector<int> &S, vector<int> &curr_subset, int set_idx, int target_sum){
    if(set_idx==S.size()){
        if(vector_sum(curr_subset)==target_sum){
            return true;
        }
    }
    else{
        if(S[set_idx]<=target_sum){
            curr_subset.emplace_back(S[set_idx]);
            bool include_ans= subset_sum_helper(S,curr_subset,set_idx+1,target_sum);
            
            if(include_ans==true){
                return include_ans;
            }
            
            curr_subset.pop_back();
            
            bool not_include_ans= subset_sum_helper(S,curr_subset,set_idx+1,target_sum);

            if(not_include_ans==true){
                return true;
            }
        }
    }
}


int vector_sum(vector<int> &V){
    int ans=0;
    for(auto x:V){
        ans+=x;
    }

    return ans;
}