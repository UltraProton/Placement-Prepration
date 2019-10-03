#include<bits/stdc++.h>

typedef  long long ll;

using namespace std;

ll stairs_memoized(ll n,ll *table);
void tab(ll n);

int main(int argc, char const *argv[])
{
    /* code */
    ll n=0;
    cin>>n;
    ll *table = new ll[n+2];

    //A new thing is learnt today
    memset(table,-1,(n+2)*sizeof(ll));

/*
    for (ll i = 0; i < n; i++)
    {
        cout<<table[i]<<" ";
    }
*/    


    cout<<stairs_memoized(n+1,table)<<endl;

    delete [] table;

    return 0;
}

ll stairs_memoized(ll n,ll *table){ 
    if(n<1){
        //table[n]=0;

        return 0;
    }

    if(n==1){
        
        //table[n]=1;

        return 1;
    }

    if(table[n]!=-1){
        return table[n];
    }

    else{
        
        table[n]= stairs_memoized(n-1,table) + stairs_memoized(n-2,table);
        
        return table[n];
    }
}

void tab(ll n){
    for(ll i=1;i<=n;i++){
        cout<<" ";
    }
}
