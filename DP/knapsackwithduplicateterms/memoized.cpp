#include<bits/stdc++.h>

using namespace std;

int knapsack(vector<int> &values, vector<int> &weights, int W, int curr_idx, vector<vector<int>> &memo);

int main(int argc, char const *argv[])
{
    /* code */

    int t=0,n=0,w=0;
    int i=0;
    vector<int> values;
    vector<int> weights;
    vector<vector<int>> memo;
    cin>>t;
    while (t>0)
    {
        cin>>n;
        cin>>w;
        values= vector<int>(n,0);
        weights= vector<int>(n,0);

        i=0;

        while(i<n){
            cin>>values[i];
            i++;
        }

        i=0;

        while(i<n){
            cin>>weights[i];
            i++;
        }

        //! The memo has to be atleast w+1 because we want the ans for weight w in the recursive call and we want ans for n-1
        //! so the memo should contain 'n' rows so the value of call (n-1,w) is stored at memo[w][n-1]    
        memo= vector<vector<int>>(n,vector<int>(w+1,-1));
        
        cout<<knapsack(values,weights,w,n-1, memo); 

        t--;
    }
    
    return 0;
}

int knapsack(vector<int> &values, vector<int> &weights, int W, int curr_idx, vector<vector<int>> &memo){
    if(W<=0 || curr_idx<0){
        return 0;
    }

    if(memo[curr_idx][W]!=-1){
        return memo[curr_idx][W];
    }

    if(weights[curr_idx]>W){
        memo[curr_idx][W]=knapsack(values,weights,W,curr_idx-1,memo);
        return memo[curr_idx][W];
    }

    else{

        int include_ans= values[curr_idx] + knapsack(values, weights, W- weights[curr_idx], curr_idx,memo);

        int exclude_ans= knapsack(values,weights,W,curr_idx-1,memo);

        memo[curr_idx][W]= max(include_ans,exclude_ans);

        return memo[curr_idx][W];

    }

}

