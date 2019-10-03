#include<bits/stdc++.h>

using namespace std;

int n_hops(int n);

int main(int argc, char const *argv[])
{
    /* code */
    int t=0;
    int n=0;
    cin>>t;
    while(t>0){
        cin>>n;
        cout<<n_hops(n)<<endl;
        t--;
    }
    return 0;
}

int n_hops(int n){
    if(n<0){
        return 0;
    }
    if(n==0){
        return 1;
    }

    else{
        return n_hops(n-1)+ n_hops(n-2)+ n_hops(n-3);
    }
}
