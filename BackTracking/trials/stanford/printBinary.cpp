#include<bits/stdc++.h>

using namespace std;

void print_binary(int n_digits, string prefix="");
void tab(int n);

int main(int argc, char const *argv[])
{
    /* code */
    print_binary(3);

    return 0;
}

/* 

The parameter n_digits indicates how many digits left to be accounted for and once we have n_digits=0 it means that
we have all the digits needed for this call in the prefix and we can now just print the prefix. n_digits=0 doesn't mean
that we will print zero digit binary string. Think of this parameter in this sense.


 */

void print_binary(int n_digits, string prefix){
    tab(prefix.size());
    cout<<"fun( n_digits= "<<n_digits<< " prefix= "<<prefix<<" )"<<endl;
    if(n_digits==0){
        cout<<prefix<<endl;
    }
    else{
        print_binary(n_digits-1, prefix+"0");
        print_binary(n_digits-1,prefix+"1");
    }
}


void tab(int n){
    for(int i=1;i<=n;i++){
        cout<<"    ";
    }
}