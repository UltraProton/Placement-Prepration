#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

ll nCk(ll n, ll k);
void tab(int n);


int main(int argc, char const *argv[])
{
    cout<<nCk(5,3)<<endl;
    return 0;
}


ll nCk(ll n, ll k){
    tab(n);
    cout<<"fun (n= "<<n<<" k= "<<k<<" )"<<endl;
    if(k==0 || n==k){
        return 1;
    }
    else{
        return nCk(n-1,k-1) + nCk(n-1,k);
    }
}

void tab(int n){
    for(int i=1;i<=n;i++){
        cout<<" ";
    }
}