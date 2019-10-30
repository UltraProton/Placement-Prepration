#include<bits/stdc++.h>

using namespace std;

int permutations(int n);
int factorial(int n);

int main(int argc, char const *argv[])
{
    int n=0;
    cin>>n;
    
    cout<<permutations(n);
    
    return 0;
}

int permutations(int n){
    vector<int> primes(n+1,1);
    primes[0]=0;
    primes[1]=0;

    for(int i=2;i*i<=n;i++){
        if(primes[i]==1){
            for(int j=2;j*i<=n;j++){
                primes[j*i]=0;
            }
        }
    }

    int prime_count= count(primes.begin(), primes.end(), 1);

    return (factorial(prime_count)%100000007)*(factorial(n-prime_count)%1000000007);
}

int factorial(int n){
    int ans=1;
    for(int i=1;i<=n;i++){
        ans*=i;
    }

    return ans;
}