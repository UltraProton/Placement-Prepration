#include<bits/stdc++.h>

using namespace std;

void Longest_palindromic_substr(string &str, vector<vector<int>> &table);

void print_table(vector<vector<int>> &table);

int main(int argc, char const *argv[])
{
    /* code */
    string str="a";

    int n=str.size();

    vector<vector<int>> table(n,vector<int>(n,0));

    Longest_palindromic_substr(str,table);

    return 0;
}

void Longest_palindromic_substr(string &str, vector<vector<int>> &table){
    int n=str.size();
    //all the length one strings are palindromes
    for(int i=0;i<n;i++){
        table[i][i]=1;
    }

    int max_len=1;
    int start_idx=0;

    //check if length 2 strings are palindrome
    for(int i=0;i<n-1;i++){
        if(str[i]==str[i+1]){
            table[i][i+1]=1;
            start_idx=i;
            max_len=2;
        }
    }

    int j=0;
    for(int len=3;len<=n;len++){
        for(int i=0;i<n-len+1;i++){
            j=i+len-1;
            if(str[i]==str[j]){
                if(table[i+1][j-1]==1){         
                    table[i][j]=1;
                    if(max_len<len){
                        max_len=len;
                        start_idx=i;
                    }
                }
            }
        }
    }

    print_table(table);
    cout<<endl;
    cout<<max_len<<endl;

    cout<<"longest palindrome: "<<str.substr(start_idx,max_len)<<endl;
}


void print_table(vector<vector<int>> &table){
    for(auto x:table){
        for(auto y:x){
            cout<<y<<"  ";
        }
        cout<<endl;
    }
}