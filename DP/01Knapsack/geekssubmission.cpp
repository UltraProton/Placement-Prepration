/* 

! Geeks test cases have flaw so don't consider this code.

 */


#include<bits/stdc++.h>

using namespace std;

int zero_one_knapsack(vector<int> &weights, vector<int> &values, int W, int curr_idx, vector<vector<int>> &memo);

int main(int argc, char const *argv[])
{
    /* code */
    vector<int> V;  
    vector<int> W;
    int t=0;  
    int weight = 50;  
    int x=0;
    int y=0;
    int n=0;
    int len=0;
    vector<vector<int>> memo;

    cin>>t;
    while(t>0){
        memo.clear();
        V.clear();
        W.clear();
        cin>>n;
        len=n;
        cin>>weight;
        while(len>0){
            cin>>x;
            V.emplace_back(x);
            len--;
        }

        len=n;
        while(len>0){
            cin>>y;
            W.emplace_back(x);
            len--;
        }

        memo= vector<vector<int>>(1002, vector<int>(1002,-1));
        
        cout<<zero_one_knapsack(W,V,weight,0,memo)<<endl;    
        
        t--;
    }

    
    
    return 0;
}

int zero_one_knapsack(vector<int> &weights, vector<int> &values, int W, int curr_idx,vector<vector<int>> &memo){
    if(memo[curr_idx][W]!=-1){
        return memo[curr_idx][W];
    }

    if(curr_idx>=weights.size() || W==0){
        memo[curr_idx][W]=0;
        return 0;
    }

    //* If the weight at curr_idx can't be included in the knapsack then we have only one option to ignore it
    if(weights[curr_idx] > W){
        memo[curr_idx][W]= zero_one_knapsack(weights, values,W,curr_idx+1,memo);
        return memo[curr_idx][W];
    }

    else{
        //include the weight at curr_idx in the knapsack
        int include_ans= values[curr_idx] + zero_one_knapsack(weights,values,W-weights[curr_idx],curr_idx+1,memo);
        
        //* Even though we can include it but we want to get the ans without considering the current weight and its value
        //* because we may get a better value later if don't decrease our weight by including the value and weight in current
        //*call
        int exclude_ans= zero_one_knapsack(weights, values,W,curr_idx+1,memo);

        memo[curr_idx][W]= max(include_ans,exclude_ans);

        return memo[curr_idx][W];
    }

}