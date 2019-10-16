#include<bits/stdc++.h>

#define mod 1000000007

using namespace std;

int possible_paths(int x, int y,int m, int n, vector<vector<int>> &memo){
    if(x<0 || x >=m || y<0 || y>=n){
        return 0;
    }

    if(memo[x][y]!=-1){
        return memo[x][y];
    }

    if(x==m-1 && y==n-1){
        memo[x][y]=1;
        return 1;
    }

    else{
        memo[x][y]=(possible_paths(x+1,y,m,n,memo)%mod+ possible_paths(x,y+1,m,n,memo)%mod)%mod; 
        return memo[x][y];
    }
}

int main(int argc, char const *argv[])
{
    /* code */

    int t=0;
    int m=0;
    int n=0;

    vector<vector<int>> memo;

    cin>>t;
    while (t>0)
    {
        cin>>m;
        cin>>n;
        memo= vector<vector<int>>(m+1,vector<int>(n+1,-1));

        cout<<possible_paths(0,0,m,n,memo)<<endl;
        
        t--;
    }
    

    return 0;
}
