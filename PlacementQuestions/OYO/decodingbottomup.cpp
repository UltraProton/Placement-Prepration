#include<bits/stdc++.h>

using namespace std;

int decodings(string &str);

int main(){
    string str="";
    cin>>str;
    
    cout<<decodings(str)<<endl;
    
    return 0;
}

int decodings(string &str){
    int n=str.size();
    /* 
    Here just do the reverse process of memoization and get the ans in the bottom up manner. Compare it with the memoized version and you
    will get more clarity.
     */

    vector<int> dp(n+1,0);
    //base case
    dp[0]=1;
    dp[1]=1;

    //Here we are going to fill the table bottomup both the conditions are same here also just the order is different and even if you look
    //closely then you will see that the order of filling the table is same in both the cases it's just difference in methodology
    for(int i=2;i<=n;i++){
        if(str[i-1]>'0'){
            dp[i]+=dp[i-1];
        }
        if(str[i-2]=='1' || (str[i-2]=='2' && str[i-1]<'7')){
            dp[i]+=dp[i-2];
        }
    }

    return dp[n];
}