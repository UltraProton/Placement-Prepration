/* 

https://leetcode.com/problems/house-robber/submissions/

 */


#include<bits/stdc++.h>

using namespace std;

int max_profit(vector<int> &Values, int l, int r, vector<vector<int>> &memo);

int main(int argc, char const *argv[])
{
    /* code */
    int t=0;
    int n=0;
    int x=0;
    int c=0;
    vector<int> Values;
    vector<vector<int>> memo;

    cin>>t;
    while (t>0)
    {   
        Values.clear();
        memo.clear();

        cin>>n;
        c=0;
        while (c<n)
        {
            cin>>x;
            Values.emplace_back(x);
            c++;
        }
        
        memo= vector<vector<int>>(n,vector<int>(n,-1));
        
        cout<<max_profit(Values,0,n-1,memo)<<endl;
        
        t--;
    }
    
    return 0;
}

int max_profit(vector<int> &Values, int l, int r, vector<vector<int>> &memo){
    if(l>r){
        return 0;
    }

    if(memo[l][r]!=-1){
        return memo[l][r];
    }

    if(l==r){
        memo[l][r]=Values[l];
        return Values[l];
    }

    if(l+1==r){
        memo[l][r]= max(Values[l], Values[r]);
        return memo[l][r];
    }

    else{
        memo[l][r]= max(Values[l]+max_profit(Values,l+2,r,memo), max_profit(Values,l+1,r,memo)); 
        return memo[l][r];
    }
}