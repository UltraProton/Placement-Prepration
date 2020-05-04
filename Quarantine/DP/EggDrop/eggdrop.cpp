#include<bits/stdc++.h>

using namespace std;

int eggdrop_rec(int k, int n);
int eggdrop_memoized(int k ,int n, vector<vector<int>> &dp);
int eggdrop_bottomup(int k ,int n);

int main(){
    return 0;
}

int eggdrop_rec(int k ,int n){
    //If we have 1 egg only then we have to try all the floors we have no choice
    if(k==1){
        return n;
    }

    //If we have 0 or 1 floor then we need 0 or 1 try no other choice here as well
    if(n==1 || n==0){
        return n;
    }

    //Otherwise we have to find the min value of the trials needed in the worst case with the given constraints
    //to find the critical floor
    int ans=INT_MAX;
    int x=0;

    /* We have made a trial throwing the egg from the ith floor
    
    2 options: 
        1. Either the egg breaks in which case we have to check for i-1 floors with one egg less
        2. If the egg doesn't break then we have our k eggs as before but we need to now check n-i floors above 
        the ith floor. 
      
      */
    //Recursive relation: f(k,n)= 1 + min(max(f(k-1,i-1),f(k,n-i)))
    //                            i=1...n
    //Try all the floors
    for(int i=1;i<=n;i++){
        x=max(eggdrop_rec(k-1,i-1),eggdrop_rec(k,n-i));
        if(ans>x){
            ans=x;
        }
    }

    return ans+1;
}

int eggdrop_bottomup(int k ,int n){
    vector<vector<int>> dp(k+1,vector<int>(n+1,100000));
    for(int i=1;i<=k;i++){
        dp[i][1]=1;
    }
    for(int i=1;i<=n;i++){
        dp[1][i]=i;
    }

    for(int i=1;i<=k;i++){
        for(int j=1;j<=n;j++){
            int x=INT_MAX;
            for(int k=1;k<=j;k++){
                x=max(dp[i-1][k-1],dp[i][j-k]);
                if(dp[i][j]>x){
                    dp[i][j]=x;
                }
            }
            dp[i][j]+=1;
        }
    }
    return dp[m][n];
}
