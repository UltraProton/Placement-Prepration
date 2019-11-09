#include<bits/stdc++.h>

using namespace std;

vector<int> seive(int n);

int main(){
	int x=0;
	cin>>x;
	
	vector<int> primes= seive(100);

    for(int i=0;i<=99;i++){
        cout<<primes[i]<<" ";
    }

    return 0;	    
}

vector<int> seive(int n){
	vector<int> primes(n+1,1);
	primes[0]=0;
	primes[1]=0;

	//If n is prime then its factor will appear in the range from 2 to sqrt(n) as the factors occur in pairs
	for(int i=2;i*i<=n;i++){
		//If the current no is prime
		if(primes[i]==1){
			//mark all the multiples of i as non prime
			for(int j=2;j*i<=n;j++){
				primes[j*i]=0;
			}
		}
	}

    return primes;
}
				