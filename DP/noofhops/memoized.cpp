#include<bits/stdc++.h>

using namespace std;

int n_hops(int n,vector<int> &memo);

int main(int argc, char const *argv[])
{
    /* code */
    int t=0;
    int n=0;
    vector<int> memo;
    cin>>t;
    while(t>0){
        memo.clear();
        cin>>n;
        memo=vector<int>(n+1,-1);
        cout<<n_hops(n,memo)<<endl;
        t--;
    }
    return 0;
}

int n_hops(int n, vector<int> &memo){
    if(n<0){
        return 0;
    }
    if(memo[n]!=-1){
        return memo[n];
    }
    if(n==0){
        memo[n]=1;
        return 1;
    }

    else{
        memo[n]= n_hops(n-1,memo)+ n_hops(n-2,memo)+ n_hops(n-3,memo);
        return memo[n];
    }
}
