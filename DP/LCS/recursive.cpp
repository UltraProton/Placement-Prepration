#include<bits/stdc++.h>

using namespace std;

int LCS(string &s1, string &s2, int m, int n);

int main(int argc, char const *argv[])
{
    /* code */
        /* code */
    string s1="a";
    string s2= "d";

    cout<<LCS(s1,s2, s1.size(), s2.size())<<endl;

    return 0;
}

int LCS(string &s1, string &s2,int m, int n){
    if(m==0 || n==0){
        return 0;
    }

    if(s1[m-1]==s2[n-1]){
        return 1+ LCS(s1,s2,m-1,n-1);
    }
    else{
        return max(LCS(s1,s2,m,n-1), LCS(s1,s2,m-1,n));
    }
}
