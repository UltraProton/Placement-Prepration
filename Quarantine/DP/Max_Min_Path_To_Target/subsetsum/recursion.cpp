#include<stdio.h>
using namespace std;

bool subset_sum(int sum, int idx, vector<int> &s);
bool subset_sum_memoized(int sum, int idx, vector<int> &s,vector<vector<int>> &dp);

int main(){
    vector<int> s{1,1};

    int m=s.size();
    int n=1;
    vector<vector<int>> dp(m,vector<int>(n+1,-1));

    cout<<subset_sum_memoized(1,1,s,dp);

}

bool subset_sum_memoized(int sum, int idx, vector<int> &s, vector<vector<int>> &dp){
    if(sum<0){
        return false;
    }
    if(idx<0 && sum>0){
        return false;
    }
    if(sum==0){
        dp[idx][sum]=true;
        return true;
    }

    if(dp[idx][sum]!=-1){
        return dp[idx][sum];
    }

    if(s[idx]>sum){
        dp[idx][sum]=subset_sum_memoized(sum,idx-1,s);
        return dp[idx][sum];
    }

    else{
        dp[idx][sum]=subset_sum_memoized(sum,idx-1,s)+ subset_sum_memoized(sum-s[idx],idx-1,s);
        return dp[idx][sum];
    }    
}

bool subset_sum(int sum, int idx, vector<int> &s){
    if(sum<0){
        return false;
    }
    if(idx<0 && sum>0){
        return false;
    }
    if(sum==0){
        return true;
    }

    if(s[idx]>sum){
        return subset_sum(sum,idx-1,s);
    }

    else{
        return subset_sum(sum,idx-1,s)+ subset_sum(sum-s[idx],idx-1,s);
    }
}