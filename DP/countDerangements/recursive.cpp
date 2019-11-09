#include<bits/stdc++.h>

using namespace std;

int count(int n);

int main(int argc, char const *argv[])
{
    /* code */
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n=0;
    
    cin>>n;

    cout<<count(n)<<endl;
    
    return 0;
}

int count(int n){
    if(n==0){
        return 1;
    }

    if(n==1){
        return 0;
    }

    if(n==2){
        return 1;
    }

    return (n-1)*(count(n-1)+count(n-2));
}

