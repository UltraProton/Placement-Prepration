#include<bits/stdc++.h>

using namespace std;

int decode_count(string &str);

int main(int argc, char const *argv[])
{
    /* code */ 
    int t=0;
    int n=0;
    string str;

    cin>>t;
    while(t>0){
        str.clear();
        cin>>n;
        cin>>str;
        cout<<decode_count(str);
        t--;
    }
    return 0;
}

//* The idea is to first calculate the ans for shorter length substrings i.e for calculating ans for length n string first 
//* calculate ans for n-1,n-2, n-3......3,2,1 and use their values to get the ans to n

int decode_count(string &str){
    int n=str.size();
    vector<int> table(n+1,0);

    table[0]=1; //* Empty string has one decoding possible

    if(str[0]!='0'){
        table[1]=1;
    }

    if(n==1){
        return table[1];
    }

    for(int i=2;i<=n;i++){
        if(str[i-1]>='1'){
            table[i]= table[i] + table[i-1];
        }

        if(str[i-2]=='1' || str[i-2]=='2' && str[i-1]<'7'){
            table[i]= table[i] +table[i-2];
        }
    }

    return table[n];
}