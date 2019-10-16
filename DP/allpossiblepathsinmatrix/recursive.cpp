#include<bits/stdc++.h>

using namespace std;

int possible_paths(int x, int y,int m, int n){
    if(x<0 || x >=m || y<0 || y>=n){
        return 0;
    }

    if(x==m-1 && y==n-1){
        return 1;
    }

    else{
        return (possible_paths(x+1,y,m,n)+ possible_paths(x,y+1,m,n));
    }
}

int main(int argc, char const *argv[])
{
    /* code */

    int t=0;
    int m=0;
    int n=0;

    cin>>t;
    while (t>0)
    {
        cin>>m;
        cin>>n;
        cout<<possible_paths(0,0,m,n)<<endl;
        t--;
    }
    

    return 0;
}
