#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

ll perfect_sum(vector<ll> &S, int curr_idx, int target_sum, vector<vector<ll>> &memo);

int main(int argc, char const *argv[])
{
    vector<ll> S;
    int t=0,n=0,x=0,target=0;

    vector<vector<ll>> memo;

    cin>>t;

    while(t>0){
        memo.clear();
        S.clear();
        cin>>n;
        while(n>0){
            cin>>x;
            S.emplace_back(x);
            n--;
        }
        cin>>target;

        memo= vector<vector<ll>>(1000, vector<ll>(1000,-1));

        cout<<perfect_sum(S,S.size(),target,memo);

        cout<<endl;

        t--;
    }
    

    return 0;
}

ll perfect_sum(vector<ll> &S, int curr_idx, int target_sum,vector<vector<ll>> &memo){
    // negative target sum can't have a solution
    if(target_sum < 0){
        return 0;
    }
    
    //empty set is the solution in this case
    if(target_sum==0){
        memo[curr_idx][target_sum]=1;
        return 1;
    }

    // ! Always remember that here the condition of already having stored ans is after the above 2 conditions because
    // ! we don't want to access invalid indices in the table if we have this condition before checking target_sum < 0
    // ! then we will be accessing invalid indices
    
    if(memo[curr_idx][target_sum]!=-1){
        return memo[curr_idx][target_sum];
    }

    // * if we have traversed the whole set and still the target sum is positive then we could not find the solution
    if(curr_idx<=0 && target_sum>0){
        return 0;
    }

    else{
        memo[curr_idx][target_sum]= (
                                    perfect_sum(S,curr_idx-1,target_sum,memo) + 
                                    perfect_sum(S,curr_idx-1, target_sum-S[curr_idx-1],memo)
                                    );

        return memo[curr_idx][target_sum];
    }

}
