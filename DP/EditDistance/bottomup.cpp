#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

ll edit_dist(string &s1, string &s2);
void print_table(vector<vector<ll>> &table);

int main(int argc, char const *argv[])
{

    string s1="abc";
    string s2= "abcdef";

    cout<<edit_dist(s1,s2)<<endl;

    return 0;
}


ll edit_dist(string &s1, string &s2){
    ll edit_dist=0;
    ll m=s1.size();
    ll n=s2.size();
    
    vector<vector<ll>> table(10,vector<ll>(10,0));

    

    for(int i=0;i<=m;i++){
        for(int j=0;j<=n;j++){
            if(i==0){
                table[i][j]=j;
            }
            else if(j==0){
                table[i][j]=i;
            }
            else if(s1[i-1]==s2[j-1]){
                table[i][j]= table[i-1][j-1];
            }
            else{
                table[i][j]= 1+ min(table[i-1][j-1], min(table[i-1][j], table[i][j-1]));
            }
        }
    }

    print_table(table);

    return table[m][n];
}

void print_table(vector<vector<ll>> &table){
    for(auto vec:table){
        for(auto ele:vec){
            cout<<ele<<"    ";
        }
        cout<<endl;
    }
}