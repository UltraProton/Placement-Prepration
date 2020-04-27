#include<bits/stdc++.h>

using namespace std;

int decode_ways_recursive(string s);
int decode_ways_memoized(string s);

 int numDecodings(string s) {
    //If the string is just "0" or starting with '0' then there is no decoding possible
    if(s=="0" || s[0]=='0'){
        return 0;
    }

    int n=s.size();
    //dp[n] stores ans for the string of length n
    vector<int> dp(n+1,0);

    dp[0]=1; //An empty string has 1 decoding
    dp[1]=1; //A string of length 1 will have 1 decoding
    for(int i=2;i<=n;i++){
        //If the character at index i-1 is any other digit but not '0' then it can be decoded as some character
        //and can be added to the answer
        if(s[i-1]!='0'){
            dp[i]+=dp[i-1];
        }
        //Considering length 2 substring it should be less than 27 if it is then it can be decoded and can be added
        //to the ans
        if((s[i-1]<'7' && s[i-2]=='2') || s[i-2]=='1'){
            dp[i]+=dp[i-2];
        }
    }
    
    return dp[n];
    
}

int main(){

}