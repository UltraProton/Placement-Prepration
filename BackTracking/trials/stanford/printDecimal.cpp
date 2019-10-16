/* 

diceRoll, printBinary, printDecimal are not typical examples of choose , explore and unchoose paradigm.

 */




#include<bits/stdc++.h>

using namespace std;

void print_decimal(int n_digits);
void print_decimal_helper(int n_digits, string curr="");

int main(int argc, char const *argv[])
{   
    print_decimal(2);
    
    return 0;
}

void print_decimal(int n_digits){
    print_decimal_helper(n_digits);
}

void print_decimal_helper(int n_digits, string curr){
    if(n_digits==0){
        cout<<curr<<endl;
    }
    else{
        /* Here I have many choices to make so why not just write it inside a loop. Remember in  printBinary we
        had only 2 choices so we hade written those calls there without loop */
        for(int i=1;i<=9;i++){
            print_decimal_helper(n_digits-1, curr+ to_string(i));
        }
    }
}
