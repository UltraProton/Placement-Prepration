#include<bits/stdc++.h>

using namespace std;

int LCS(string &s1, string &s2);

void print_table(vector<vector<int>> &table);

int main(int argc, char const *argv[])
{
    string s1="ABCDGH";
    string s2= "AEDFHR";

    cout<<LCS(s1,s2)<<endl;
    
    return 0;
}

int LCS(string &s1, string &s2){
    vector<vector<int>> table(10,vector<int>(10,-1));
    int m=s1.size();
    int n=s2.size();

    for(int i=0;i<=m;i++){
        for(int j=0;j<=n;j++){
            if(i==0 || j==0){
                table[i][j]=0;
            }
            /* Remember to have else if condition not if(s1[i-1]==s2[j-1]) it will consider 0 index of i and
            j after passing above if condition. 
            */
            else if(s1[i-1]==s2[j-1]){
                table[i][j]= 1+ table[i-1][j-1];
            }
            else{
                table[i][j]= max(table[i-1][j], table[i][j-1]);
            }
        }
    }

    print_table(table);

    return table[m][n];
}



void print_table(vector<vector<int>> &table){
    for(auto vec:table){
        for(auto ele:vec){
            cout<<ele<<"    ";
        }
        cout<<endl;
    }
}