#include<bits/stdc++.h>

using namespace std;

typedef long long ll;


//***********A way to not have the global 2d array but passing a pointer to the 2d array declared inside main************************************


#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

ll nCk(ll n, ll k, ll (*)[1000][500]);
void tab(int n);


int main(int argc, char const *argv[])
{   ll table[1000][500];
    ll (*tab)[1000][500]= &table;
    memset(table,0,sizeof(table));
    cout<<nCk(10,6,tab)<<endl;
    return 0;
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

void tab(int n){
    for(int i=1;i<=n;i++){
        cout<<" ";
    }
}



