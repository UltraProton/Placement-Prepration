#include<bits/stdc++.h>

using namespace std;

bool subset_sum(vector<int> &S, int curr_idx, int target_sum );

int main(int argc, char const *argv[])
{
    vector<int> S{1,2,3};

    cout<<subset_sum(S,0,4)<<endl;

    return 0;
}

bool subset_sum(vector<int> &S , int curr_idx, int target_sum){
    if(target_sum<0){
        return false;
    }

    if(target_sum==0){
        return true;
    }

    if(curr_idx>=S.size() && target_sum > 0){
        return false;
    }
    
    else{
        return (subset_sum(S,curr_idx+1,target_sum-S[curr_idx]) || subset_sum(S,curr_idx+1,target_sum));
    }
}