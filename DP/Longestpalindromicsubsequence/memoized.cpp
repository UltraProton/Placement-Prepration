#include<bits/stdc++.h>

using namespace std;

int LPSubSeq(string s,int l,int r, vector<vector<int>> &memo);
void print_memo(vector<vector<int>> &memo);

int main(){
    string str="abacb";
    int n=str.size();

    vector<vector<int>> memo(n,vector<int>(n,-1));
    
    cout<<LPSubSeq(str,0,str.size()-1,memo)<<endl;

    print_memo(memo);
    
    return 0;
}

int LPSubSeq(string s,int l,int r, vector<vector<int>> &memo){
    //we already have answer between the indices l and r
    if(memo[l][r]!=-1){
        return memo[l][r];
    }

    //if the indices l and r crosses then we can't find Longest palindromic subsequence
    if(l>r){
        memo[l][r]=0;
        return 0;
    }

    //only one character so we have only one length palindrome
    if(l==r){
        memo[l][r]=1;
        return 1;
    }

    //more than 1 characters between l and r and the last characters match
    if(s[l]==s[r]){
        memo[l][r]= 2+ LPSubSeq(s,l+1,r-1,memo);
        return memo[l][r];
    }

    else{
        memo[l][r]=max(LPSubSeq(s,l,r-1,memo),LPSubSeq(s,l+1,r,memo)); 
        return memo[l][r];
    }
}

void print_memo(vector<vector<int>> &memo){
    for(auto x:memo){
        for(auto y:x){
            cout<<y<<"        ";
        }
        cout<<endl;
    }
}