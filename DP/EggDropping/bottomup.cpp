#include<bits/stdc++.h>

using namespace std;

int egg_drop(int e, int n);

int main(int argc, char const *argv[])
{
    /* code */
    int e=0;
    int floors=0;
    int t=0;
    vector<vector<int>> memo;

    cin>>t;

    while(t>0){
        cin>>e>>floors;
        cout<<egg_drop(e,floors)<<endl;
        t--;
    }

    // char c='y';
    // while(c=='y'){
    //     cin>>e;
    //     cin>>floors;
    //     cout<<"ans: "<< egg_drop(e,floors)<<endl;
    //     cout<<"enter: character : ";
    //     cin>>c;
    // }
    // 
    return 0;
}

int egg_drop(int e, int n){
    vector<vector<int>> table(e+1, vector<int>(n+1,0));

    for(int i=1;i<=e;i++){
        for(int j=1;j<=n;j++){
            if(i==1){
                table[i][j]=j;
            }
            else{
                int ans=INT_MAX;
                for(int k=1;k<=j;k++){
                        ans= min(ans, 1+ max(table[i-1][k-1], table[i][j-k]));
                }
                table[i][j]=ans;
            }
        }
    }

    // for(auto vec:table){
    //     for(auto ele: vec){
    //         cout<<ele<<" ";
    //     }
    //     cout<<endl;
    // }

    return table[e][n];
}
