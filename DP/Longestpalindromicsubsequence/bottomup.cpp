#include<bits/stdc++.h>

using namespace std;

int LPSubSeq(string s, vector<vector<int>> &table);
void print_table(vector<vector<int>> &table);
int LPSubSeq_good(string s,vector<vector<int>> &table);

int main(){
    string str="GEEKS FOR GEEKS";
    int n=str.size();

    vector<vector<int>> table(n,vector<int>(n,0));
    
    cout<<LPSubSeq_good(str,table)<<endl;

    print_table(table);
    
    return 0;
}

int LPSubSeq(string s,vector<vector<int>> &table){
    int max_len=INT_MIN;
    //all the length 1 subsequence are palindromes
    for(int i=0;i<s.size();i++){
        table[i][i]=1;
    }

    //find all the length 2 subsequnces if they are palindrome or not
    for(int i=0;i<s.size()-1;i++){
        if(s[i]==s[i+1]){
            table[i][i+1]=2;
            max_len=2;
        }
        else{
            table[i][i+1]=1;
        }
    }

    for(int l=3;l<=s.size();l++){
        for(int i=0;i<=s.size()-l;i++){
            int j=i+l-1;
            
            if(s[i]==s[j]){
                table[i][j]= 2+ table[i+1][j-1];
            }

            else{
                table[i][j]= max(table[i+1][j],table[i][j-1]);
            }
        }
    }

    return table[0][s.size()-1];
}


int LPSubSeq_good(string s,vector<vector<int>> &table){
    int max_len=INT_MIN;
    //all the length 1 subsequence are palindromes
    for(int i=0;i<s.size();i++){
        table[i][i]=1;
    }

    // here we dont need to handle the case of length 2 separately
    // //find all the length 2 subsequnces if they are palindrome or not
    // for(int i=0;i<s.size()-1;i++){
    //     if(s[i]==s[i+1]){
    //         table[i][i+1]=2;
    //         max_len=2;
    //     }
    //     else{
    //         table[i][i+1]=1;
    //     }
    // }

    for(int l=2;l<=s.size();l++){
        for(int i=0;i<=s.size()-l;i++){
            int j=i+l-1;

            // if(s[i]==s[j] && l==2){
            //     table[i][j]= 2;
            // }

            if(s[i]==s[j]){
                table[i][j]=  2 + table[i+1][j-1];
            }

            else{
                table[i][j]= max(table[i+1][j],table[i][j-1]);
            }
        }
    }

    return table[0][s.size()-1];
}






void print_table(vector<vector<int>> &table){
    for(auto x:table){
        for(auto y:x){
            cout<<y<<" ";
        }
        cout<<endl;
    }
}