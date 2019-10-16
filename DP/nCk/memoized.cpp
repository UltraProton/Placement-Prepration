#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

ll nCk(ll n, ll k);
void tab(int n);

ll table[1000][500];

int main(int argc, char const *argv[])
{   
    memset(table,-1,sizeof(table));
    cout<<nCk(212,169)<<endl;
    return 0;
}


ll nCk(ll n, ll k){
    /* special case */
    if(k>n){
        return 0;
    }
    if(k==0 || n==k){
        return 1;
    }

     if(table[n][k]!=-1){
        return table[n][k];
    }
    
    table[n][k]= nCk(n-1,k-1)%1000000007 + nCk(n-1,k)%1000000007;

    return table[n][k]%1000000007;
}

void tab(int n){
    for(int i=1;i<=n;i++){
        cout<<" ";
    }
}


/*


***********A way to not have the global 2d array but passing a pointer to the 2d array declared inside main************************************


#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

ll nCk(ll n, ll k, ll (*)[1000][500]);
void tab(int n);


int main(int argc, char const *argv[])
{   ll table[1000][500];
    ll (*tab)[1000][500]= &table;
    memset(table,-1,sizeof(table));
    cout<<nCk(212,169,tab)<<endl;
    return 0;
}


ll nCk(ll n, ll k, ll (*table)[1000][500]){
    // special case 
    if(k>n){
        return 0;
    }
    if(k==0 || n==k){
        return 1;
    }

     if((*table)[n][k]!=-1){
        return (*table)[n][k];
    }
    
    *table[n][k]= nCk(n-1,k-1,table)%1000000007 + nCk(n-1,k,table)%1000000007;

    return *table[n][k]%1000000007;
}

void tab(int n){
    for(int i=1;i<=n;i++){
        cout<<" ";
    }
}

*/