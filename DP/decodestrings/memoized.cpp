#include<bits/stdc++.h>

using namespace std;

int decode_count(string &str, int n, unordered_map<string, int> &mp, vector<int> &memo);
bool is_valid(string &str,unordered_map<string,int> &mp);

int main(){
    int t=0;
    int n=0;
    string str;
    unordered_map<string,int> mp;
    // for(int i='A';i<='Z';i++){
    //     mp[to_string(i)]=1; //* To string function will convert the integer 
    // }

    mp["1"]=1;
    mp["2"]=1;
    mp["3"]=1;
    mp["4"]=1;
    mp["5"]=1;
    mp["6"]=1;
    mp["7"]=1;
    mp["8"]=1;
    mp["9"]=1;
    mp["10"]=1;
    mp["11"]=1;
    mp["12"]=1;
    mp["13"]=1;
    mp["14"]=1;
    mp["15"]=1;
    mp["16"]=1;
    mp["17"]=1;
    mp["18"]=1;
    mp["19"]=1;
    mp["20"]=1;
    mp["21"]=1;
    mp["22"]=1;
    mp["23"]=1;
    mp["24"]=1;
    mp["25"]=1;
    mp["26"]=1;

    vector<int> memo;

    cin>>t;
    while(t>0){
        str.clear();
        cin>>n;
        cin>>str;
        memo= vector<int>(n+1,-1);

        cout<<decode_count(str,n,mp,memo);
        t--;
    }
    return 0;
}


int decode_count(string &str, int n, unordered_map<string, int> &mp, vector<int> &memo){

    if(memo[n]!=-1){
        return memo[n];
    }

    if(n==0 || n==1){
        memo[n]=1;
        return 1;
    }
    
    else{
        int ans=0;
        if(n>0){
            string last= str.substr(n-1,1);
            if(is_valid(last,mp)){
                ans+= decode_count(str,n-1,mp,memo);
            }
        }

        if(n>1){
            string second_last= str.substr(n-2,2);
            if(is_valid(second_last,mp)){
                ans+=decode_count(str,n-2,mp,memo);
            }
        }

        memo[n]=ans;

        return memo[n];
    }
}

bool is_valid(string &str, unordered_map<string, int> &mp){
    if(mp[str]==1){
        return true;
    }

    else{
        return false;
    }
}

