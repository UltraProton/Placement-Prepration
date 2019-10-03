#include<bits/stdc++.h>

using namespace std;

int knapsack(vector<int> &values, vector<int> &weights, int W, int curr_idx);

int main(int argc, char const *argv[])
{
    /* code */

    int t=0,n=0,w=0;
    int i=0;
    vector<int> values;
    vector<int> weights;
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
        
        cout<<knapsack(values,weights,w,n-1);

        t--;
    }
    
    return 0;
}

int knapsack(vector<int> &values, vector<int> &weights, int W, int curr_idx){
    if(W<=0 || curr_idx<=0){
        return 0;
    }

    if(weights[curr_idx]>W){
        return knapsack(values,weights,W,curr_idx-1);
    }

    if(weights[curr_idx]<=W){

        return max(values[curr_idx] + knapsack(values, weights, W- weights[curr_idx], curr_idx), 
        (knapsack(values,weights,W,curr_idx-1))); 

    }

}

