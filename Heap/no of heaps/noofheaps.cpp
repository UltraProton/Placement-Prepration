#include<bits/stdc++.h>

using namespace std;

typedef  long long ll;

#define mod (1000000007)

ll heap_count(ll n, ll (*table)[1000][500]);
ll heap_count_memoized(ll n, ll (*table)[1000][500], ll *memo);
ll l_subtree_count(ll n);
ll nCk(ll n, ll r, ll (*table)[1000][500]);

int main(){
    ll table[1000][500];
    memset(table,0,sizeof(table));
    ll (*tab)[1000][500]= &table;
    ll memo[1000];

    try{
        memset(memo, -1,sizeof(memo));
    }
    catch(exception e){
        cout<<"memory not available"<<endl;
    }

    cout<<memo[3]<<endl;

    ll n=0;
    cin>>n;
    //cout<<l_subtree_count(n)<<endl;
    //cout<<heap_count_memoized(n, tab, memo)<<endl;
    cout<<heap_count(n,tab)<<endl;
    return 0;

}

ll heap_count(ll n, ll (*table)[1000][500]){
    if(n<=1){
        return 1;
    }
    else
    {
        ll L= l_subtree_count(n);
        ll R= n-1-L;
        return (nCk(n-1,L, table) * heap_count(L, table)%mod * heap_count(R, table)%mod)%mod;
    }
}

ll heap_count_memoized(ll n, ll (*table)[1000][500], ll *memo){
    if(n<=1){
        return 1;
    }

    if(memo[n]!=-1){
        return memo[n];
    }

    ll L= l_subtree_count(n);
    ll R= n-1-L;
    memo[n]= (nCk(n-1,L, table) * heap_count_memoized(L, table,memo)%mod * heap_count_memoized(R, table,memo)%mod)%mod;
    
    return memo[n];
}


ll l_subtree_count(ll n){
    ll h= log2(double(n));
    ll m= (1<<h);
    ll p= n-m+1;
    if(p>=m/2){
        return m-1;
    }
    else{
        return (m-1-(m/2-p));
    }
}


ll nCk(ll n, ll k, ll (*table)[1000][500]){
    for(int i=0;i<=n;i++){
        for(int j=0;j<=k;j++){   
            //cout<<"[i= "<<i<<", j= "<<j<<" ]"<<endl;
            if(i<j || i<1){
                continue;
            }     
            else if(j==0 || i==j){
                (*table)[i][j]= 1;
            }        
            else{
                (*table)[i][j]= (*table)[i-1][j]%1000000007+ (*table)[i-1][j-1]%1000000007;
                //cout<<"x"<<endl;
            }
        }
    }

    return (*table)[n][k]%1000000007;
}