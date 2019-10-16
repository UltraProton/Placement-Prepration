#include<bits/stdc++.h>

using namespace std;

int zero_one_knapsack(vector<int> &weights, vector<int> &values, int W, int curr_idx);

int main(int argc, char const *argv[])
{
    /* code */
    vector<int> V{60, 100, 120};  
    vector<int> W{10, 20, 30};  
    int w = 50;  
    cout<<zero_one_knapsack(W,V,w,0)<<endl;
    return 0;
}

int zero_one_knapsack(vector<int> &weights, vector<int> &values, int W, int curr_idx){
    if(curr_idx>=weights.size() || W==0){
        return 0;
    }

    //* If the weight at curr_idx can't be included in the knapsack then we have only one option to ignore it
    if(weights[curr_idx] > W){
        return zero_one_knapsack(weights, values,W,curr_idx+1);
    }

    else{
        //include the weight at curr_idx in the knapsack
        int include_ans= values[curr_idx] + zero_one_knapsack(weights,values,W-weights[curr_idx],curr_idx+1);
        
        //* Even though we can include it but we want to get the ans without considering the current weight and its value
        //* because we may get a better value later if don't decrease our weight by including the value and weight in current
        //*call
        int exclude_ans= zero_one_knapsack(weights, values,W,curr_idx+1);

        return max(include_ans,exclude_ans);
    }

}

