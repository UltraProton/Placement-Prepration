#include<stdio.h>

using namespace std;

int coin_change_my(int amount, vector<int> &coins);
int coin_change_elegant(int amount, vector<int> &coins);
int coin_change_beauty(int amount, vector<int> &coins);

int main(){

}

int coin_change_my(int amount, vector<int> &coins){
    int m=coins.size();
    vector<vector<int>> dp(m,vector<int>(amount+1,0));
    for(int i=0;i<m;i++){
        for(int j=0;j<=amount;j++){
            if(j==0){
                dp[i][j]=1;
                continue;
            }

            if(i-1>=0){
                dp[i][j]=dp[i-1][j];
            }
            
            if(j-coins[i]>=0){
                dp[i][j]+=dp[i][j-coins[i]];
            }
        }
    }

    return dp[m-1][amount];
}

int coin_change_elegant(int amount, vector<int> &coins){
    int m=coins.size();
    vector<vector<int>> dp(m+1,vector<int>(n+1,0));
    //Preprocessing step
    dp[0][0]=1;
    for(int i=1;i<=m;i++){
        dp[i][0]=1; //Important step. Either can be done in preprocessing or here
        for(int j=1;j<=amount;j++){
        /* Notice that we always have to add dp[i-1][j] when the index is valid which is taken care of 
            here. For cases of dp[i][0] 1 will be correctly placed here.  
         */
            dp[i][j]=dp[i-1][j]; //? Don't include the coin in the ans
            if(j-coins[i-1]>=0){
                dp[i][j]+=dp[i][j-coins[i-1]]; //? Include the coin in the ans. Notice i is not changed here
            }
        }
    }

    return dp[m][n];
}

int coin_change_beauty(int amount, vector<int> &coins){
    vector<int> dp(amount+1);
    m=coins.size();
    dp[0]=1;
    for(int i=0;i<m;i++){
        for(int j=1;j<=amount;j++){
            if(j-coins[i]>=0){
                dp[j]+=dp[j-coins[i]];
            }
        }
    }
    return dp[amount];
}