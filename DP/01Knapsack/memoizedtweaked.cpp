/* 
? Case : a
* Here we are traversing from left to right in the weights and values vectors.In the call at the main function we want the
* answer to zero_one_knapsack(W,V,w,0,memo) so the final ans will be stored at memo[0][w].

? Case : b
* One more strategy is to go from right to left zero_one_knapsack(W,V,w,n,memo) then the ans will be at memo[n][w].
* Remember the memo size should be n*w.
* It makes more sense to go with the second case.

 */

#include<bits/stdc++.h>

using namespace std;

int zero_one_knapsack(vector<int> &weights, vector<int> &values, int W, int curr_idx, vector<vector<int>> &memo);
void print_memo(vector<vector<int>> &memo);

int main(int argc, char const *argv[])
{
    /* code */
    vector<int> V{1, 2, 3};  
    vector<int> W{1, 2, 2};  
    int w = 4;  

    vector<vector<int>> memo(V.size()+1, vector<int>(w+2,-1));

    cout<<zero_one_knapsack(W,V,w,V.size(),memo)<<endl;

    print_memo(memo);

    return 0;
}

int zero_one_knapsack(vector<int> &weights, vector<int> &values, int W, int curr_idx,vector<vector<int>> &memo){
    //
    if(curr_idx==0 || W==0){
        memo[curr_idx][W]=0;
        return 0;
    }

    //* The above condition needs to be before the following if condition because we don't wan't to access invalid
    //* index in our code
    if(memo[curr_idx][W]!=-1){
        return memo[curr_idx][W];
    }

    //* If the weight at curr_idx can't be included in the knapsack then we have only one option to ignore it
    if(weights[curr_idx] > W){
        memo[curr_idx][W]= zero_one_knapsack(weights, values,W,curr_idx-1,memo);
        return memo[curr_idx][W];
    }

    else{
        //include the weight at curr_idx in the knapsack
        int include_ans= values[curr_idx] + zero_one_knapsack(weights,values,W-weights[curr_idx],curr_idx-1,memo);
        
        //* Even though we can include it but we want to get the ans without considering the current weight and its value
        //* because we may get a better value later if don't decrease our weight by including the value and weight in current
        //*call
        int exclude_ans= zero_one_knapsack(weights, values,W,curr_idx-1,memo);

        memo[curr_idx][W]= max(include_ans,exclude_ans);

        return memo[curr_idx][W];
    }

}

void print_memo(vector<vector<int>> &memo){
    for(auto vec:memo){
        for(auto ele:vec){
            cout<<ele<<" ";
        }
        cout<<endl;
    }
}