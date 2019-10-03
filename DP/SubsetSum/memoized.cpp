#include<bits/stdc++.h>

using namespace std;

bool subset_sum(vector<int> &S, int curr_idx, int target_sum ,vector<vector<int>> &memo);

int main(int argc, char const *argv[])
{
    vector<int> S;
    vector<vector<int>> memo(100, vector<int>(100,-1));

    int t=0;
    int n=0;
    int x=0;
    int target=0;
    cin>>t;
    while(t>0){
        S.clear();
        cin>>n;
        while(n>0){
            cin>>x;
            S.emplace_back(x);
            n--;
        }

        cin>>target;

        cout<<subset_sum(S,0,target,memo)<<endl;
        
        t--;
    }

    
    return 0;
}

bool subset_sum(vector<int> &S , int curr_idx, int target_sum,vector<vector<int>> &memo){
    if(target_sum<0){
        return false;
    }

    if(curr_idx>=S.size() && target_sum > 0){
        return false;
    }
    
    if(memo[curr_idx][target_sum]!=-1){
        return memo[curr_idx][target_sum];
    }


    if(target_sum==0){
        memo[curr_idx][target_sum]=1;
        return true;
    } 
    
    else{
        memo[curr_idx][target_sum]= (subset_sum(S,curr_idx+1,target_sum-S[curr_idx],memo) 
                                        || 
                                    subset_sum(S,curr_idx+1,target_sum,memo)); 
        
        return memo[curr_idx][target_sum]; 
    }
}