#include<bits/stdc++.h>

using namespace std;

int lc_substr(string &s1, string &s2);

int main(int argc, char const *argv[])
{
    /* code */
    string s1="OldSite:GeeksforGeeks.org";
    string s2="NewSite:GeeksQuiz.com";

    cout<<lc_substr(s1,s2)<<endl;

    return 0;
}

int lc_substr(string &s1, string &s2){
    int m=s1.size();
    int n=s2.size();

    int ans=0;

    vector<vector<int>> table(m+1,vector<int>(n+1,0));

    for(int i=0;i<=m;i++){
        for(int j=0;j<=n;j++){
            if(i==0 || j==0){
                table[i][j]=0;
            }
            
            else if(s1[i-1]==s2[j-1]){
                table[i][j]= 1+ table[i-1][j-1];
                ans=max(ans, table[i][j]);
            }

            else {
                table[i][j]=0;
            }
        }
    }

    return ans;
}
