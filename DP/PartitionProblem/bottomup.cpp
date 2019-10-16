
/* 
? Failed test case: 
8
478 757 314 471 729 100 459 618

*/ 

#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

bool partition_possible(vector<ll> &S);
bool subset_sum(vector<ll> &S, ll target);
ll sum(vector<ll> &S);

int main(int argc, char const *argv[])
{
    vector<ll> S{478 ,757 ,314 ,471 ,729 ,100 ,459 ,618};
    
    cout<<partition_possible(S)<<endl;

    return 0;
}

bool partition_possible(vector<ll> &S){
    
    ll set_sum= sum(S);

    if(set_sum%2){
        return false;
    }

    return subset_sum(S,set_sum/2);
}


bool subset_sum(vector<ll> &S, ll target){
    int m=S.size();

    vector<vector<ll>> table(5000,vector<ll>(5000,0));

    for(int i=0;i<m;i++){
        for(int j=0;j<=target;j++){
            if(j==0){
                /* 
                *If the target is 0 then the empty set is the solution as it's sum is zero
                *  
                * */

                table[i][j]=1;
                continue;
            }
            // * Dont include the element at the index i-1 in the subset 
            if(i-1>=0){
                table[i][j]= table[i][j] || table[i-1][j];
            }

            // * include the element at the index i-1 in the set so we 
            if(i-1>=0 && j-S[i]>=0){
                table[i][j]= table[i][j] || table[i-1][j-S[i]];
            }
        }
    }

    return table[m-1][target];
}



ll sum(vector<ll> &S){
    ll ans=0;
    for(auto x:S){
        ans+=x;
    }

    return ans;
}
