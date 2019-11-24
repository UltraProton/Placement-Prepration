#include<bits/stdc++.h>

using namespace std;

int decodings(string &str, int n,vector<int> &memo);

int main(){
    string str="";
    cin>>str;
    
    vector<int> memo(str.size()+1,-1);


    cout<<decodings(str,str.size(),memo)<<endl;
    
    return 0;
}

int decodings(string &str, int n,vector<int> &memo){
    if(memo[n]!= -1){
        return memo[n];
    }

    if(n==0 || n==1){
        memo[n]=1;
        return 1;
    }

    int ans=0;

    if(str[n-1]>'0'){
        ans+=decodings(str,n-1,memo);
    }

    if(str[n-2]=='1' || (str[n-2]=='2' && str[n-1]<'7')){
        ans+=decodings(str,n-2,memo);
    }

    memo[n]=ans;

    return memo[n];
}

//!Below solution is incorrect
//?The base case is incorrect doesn't handle n==1 case
/* int decodings(string str ,int n){
    if(n==0){
        return 1;
    }

    else{
        int x=0,y=0;
        ?We should only add the last digit to the result only if it is non-zero in the problem 0 doesn't correspond to any alphabet
        if(str.size()>=1) 
        y=decodings(str.substr(0,n-1),n-1);

        if(str.size()>=2 && str[n-1]-'0'<7 && str[n-2]-'0'<=2)
        x=decodings(str.substr(0,n-2),n-2);
        
        return x+y;
    }
} 
*/