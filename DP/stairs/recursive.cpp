#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

ll stairs_recursive(ll n, ll i);
void tab(ll n);

int main(int argc, char const *argv[])
{
    /* code */
    ll n=0;
    cin>>n;
    cout<<stairs_recursive(n,0)<<endl;

    return 0;
}

ll stairs_recursive(ll n,ll i){
    //tab(i);
    //cout<<"fun( n= "<<n<<" i= "<<i<<")"<<endl;

    if(n<1){
        return 0;
    }

    if(n==1){
        return 1;
    }

    else{
        
        i++;
        return stairs_recursive(n-1,i) + stairs_recursive(n-2,i);
    }
}

void tab(ll n){
    for(ll i=1;i<=n;i++){
        cout<<" ";
    }
}
