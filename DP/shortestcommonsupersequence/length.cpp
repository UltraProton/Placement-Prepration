#include<bits/stdc++.h>

using namespace std;

int shortest_common_supersequence(string &s1, string &s2);

int main(int argc, char const *argv[])
{
    /* code */
    int t=0;
    string s1;
    string s2;
    int m=0;
    int n=0;

    cin>>t;
    while(t>0){
        cin>>s1;
        cin>>s2;
        cout<<shortest_common_supersequence(s1,s2)<<endl;
        t--;
    }
    return 0;
}


int shortest_common_supersequence(string &s1, string &s2){
    int m=s1.size();
    int n=s2.size();

    vector<vector<int>> table(m+1, vector<int>(n+1,0));

    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(s1[i-1]==s2[j-1]){
                table[i][j]=1+ table[i-1][j-1];
            }
            else{
                table[i][j]= max(table[i-1][j], table[i][j-1]);
            }
        }
    }


    return (m+n-table[m][n]);
}
