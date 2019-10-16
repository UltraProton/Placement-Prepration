/* Print binary representation of a given integer. */

#include<bits/stdc++.h>

using namespace std;

void print_binary(int n);

int main(int argc, char const *argv[])
{
    print_binary(6);
    return 0;
}


// TODO: Do many recursion problems on strings to understand strings and recursion better

// * This function uses call stack to decide the order of printing the result

void print_binary(int n){
    if(n<2){
        cout<<n;
    }
    else{
        int last_digit= n%2;
        print_binary(n/2);
        cout<<last_digit;
    }
}

void tab(int n){
    for(int i=1;i<=n;i++){
        cout<<"    ";
    }
}