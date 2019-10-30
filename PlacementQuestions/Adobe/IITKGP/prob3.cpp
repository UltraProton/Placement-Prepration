#include<bits/stdc++.h>

using namespace std;

int lps(string &s1, string &s2);

int main(int argc, char const *argv[])
{
    /* code */
    string s1="";
    string s2="";
    cin>>s1>>s2;

    cout<<lps(s1,s2)<<endl;

    return 0;
}

int lps(string &s1, string &s2){
    string s= s1+s2;
    reverse(s.begin(),s.end());
    string t=s;
    reverse(s.begin(),s.end());

    // cout<<s<<endl;
    // cout<<t<<endl;
    int n=s.size();
    int m=t.size();
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s[i-1]==t[j-1]){
                dp[i][j]= 1+dp[i-1][j-1];
            }
            else{
                dp[i][j]= max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    return dp[n][m];    
}