#include<bits/stdc++.h>

using namespace std;

typedef long long  ll;
#define m 1000000007

long long n_ways(int n);

int main(int argc, char const *argv[])
{
    /* code */
    int n=0;
    int t=0;
    cin>>t;

    long long a=0;
    long long b=1;
    long long  ans=0;

    vector<long long> fib(100005,0);
    
    fib[0]=0;
    fib[1]=1;    
    
    for(int i=2;i<=100005;i++){
        fib[i]= (fib[i-1]%m + fib[i-2]%m)%m;
    }

    while (t>0)
    {
        cin>>n;
        cout<<fib[n+1]<<endl;
        t--;
    }
    
    return 0;
}


long long n_ways(int n){
    long long a=0;
    long long b=1;
    long long  ans=0;
    
    for(int i=2;i<=n;i++){
        ans=(a%m+b%m)%m;
        a=b;
        b=ans;
    }

    return ans;
}