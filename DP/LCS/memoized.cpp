#include<bits/stdc++.h>

using namespace std;

int LCS(string &s1, string &s2, int m, int n,vector<vector<int>> &memo);
void print_memo(vector<vector<int>> &table);

int main(int argc, char const *argv[])
{
    /* code */
    string s1="ABCDGH";
    string s2= "AEDFHR";

    vector<vector<int>> memo(10, vector<int>(10,-1));

    cout<<LCS(s1,s2, s1.size(), s2.size(),memo)<<endl;

    print_memo(memo);

    return 0;
}

int LCS(string &s1, string &s2,int m, int n,vector<vector<int>> &memo){
    if(memo[m][n]!=-1){
        return memo[m][n];
    }

    if(m==0 || n==0){
        memo[m][n]=0;
        return 0;
    }

    if(s1[m-1]==s2[n-1]){
        memo[m][n]=1+ LCS(s1,s2,m-1,n-1,memo);
        return memo[m][n];
    }
    else{
        memo[m][n] =max(LCS(s1,s2,m,n-1,memo), LCS(s1,s2,m-1,n,memo)); 
        return memo[m][n];
    }
}


void print_memo(vector<vector<int>> &memo){
    for(auto vec:memo){
        for(auto ele:vec){
            cout<<ele<<"    ";
        }
        cout<<endl;
    }
}