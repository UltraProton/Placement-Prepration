/* 

Observation: 

fib(2)= stairs(1)   = 1
fib(3) = stairs(2)  = 2
fib(4)= stairs(3)   = 3
fib(5)= stairs(4)   = 5
        .
        .
So this problem is nothing but fibonacci with the slightest change as you see above.

-> One of the extension of the problem is if we allow not just 1 and 2 steps but 1,2, 3 upto m steps to be climbed

*/

#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

ll stairs_DP(ll n, ll *table);
ll  stairs_DP_extended(ll n, ll m, ll *table);

int main(){
    ll n=0, m=0;
    cin>>n;
    cin>>m;

    ll *table= new ll[n+5];
    std::memset(table, -1, n);

    //always remember to pass the n+1 as argument to get the correct results
    cout<<stairs_DP_extended(n+1,m,table)<<endl;

/*
    for(int i=0;i<n+5;i++){
        cout<<table[i]<<" ";
    }

    cout<<endl;
*/

    return 0;
}


ll stairs_DP(ll n, ll *table){
    table[0]=0;
    table[1]=1;
    table[2]=2;

    for(ll i=3;i<=n;i++){
        table[i]= table[i-1]+ table[i-2];
    }

    return table[n];
}


ll stairs_DP_extended(ll n, ll m, ll *table){
    table[0]=0;
    table[1]=1;
    /* Here we can't just store 2 in the table as trivial case because we may have the case n=2 and m=1 */

    for(ll i=2;i<=n;i++){
        table[i]=0;
        for(ll j=1;j<=i && j<=m;j++){
            table[i]+= table[i-j];    
        }
    }

    return table[n];
}



