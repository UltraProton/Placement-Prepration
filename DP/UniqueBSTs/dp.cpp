#include<bits/stdc++.h>

using namespace std;

int unique_bst(int n){
    vector<int> dp(n+1);
    dp[0]=1;
    dp[1]=1;
    //For each value upto n 
    for(int i=2;i<=n;i++){
        //compute the no of unique bst's and save them as they will be reused in many calls
        //Here we are considering i keys as root of the BST and using the recurrence relation: G(n)= sum[i=1 to n](G(i-1)*G(n-i))
        for(int j=1;j<=i;j++){
            dp[i]+= dp[j-1]*dp[i-j];
        }
    }
    
    return dp[n];
}

