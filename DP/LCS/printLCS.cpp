#include<bits/stdc++.h>

using namespace std;

int LCS(string &s1, string &s2);

void print_table(vector<vector<int>> &table);
void print_lcs(string &s1, string &s2, vector<vector<int>> &table);

int main(int argc, char const *argv[])
{
    string s1="ABCDGH";
    string s2= "AEDFHR";

    int len= LCS(s1,s2);

    cout<<"Length of LCS: "<<len<<endl;

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

    print_lcs(s1,s2,table);

    return table[m][n];
}


void print_lcs(string &s1, string &s2, vector<vector<int>> &table){
    int m=s1.size();
    int n=s2.size();
    
    stack<int> st;

    while(m>0 && n>0){
        if(s1[m-1]==s2[n-1]){
            st.push(s1[m-1]);
            m--;
            n--;
        }
        else if(table[m-1][n] <= table[m][n-1]){
            n--;
        }
        else{
            m--;
        }
    }

    cout<<"LCS: ";
    while(!st.empty()){
        cout<<char(st.top())<<" ";
        st.pop();
    }
}


void print_table(vector<vector<int>> &table){
    for(auto vec:table){
        for(auto ele:vec){
            cout<<ele<<"    ";
        }
        cout<<endl;
    }
}