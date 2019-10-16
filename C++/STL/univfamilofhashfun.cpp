#include<iostream>

using namespace std;

long long baseconversion(long long x, int base_x, int base_y);
long long base10conversion(long long x, long long base_x);
long long reverseofno(long long num);
long long reverseofnoRec(long long);
long long base10conversionRec(long long x, long long base_x);

int main(void){
    long long num=0;
    cout << "Enter no to reverse: "<< endl;
    cin >> num;

    //cout << endl<< "reverse of no: "<< reverseofno(num) <<endl;
    //cout << endl << "reverse of no recursive: " << reverseofnoRec(num) << endl;
    cout << endl << "conversion:  " << base10conversionRec(num,15) << endl;

    return 0;

}
long long reverseofno(long long x){
    long long ans=0;
    for(;x > 0; x/=10){
        ans= ans * 10 + x%10;
    }
    return ans;
}

/*
long long reverseofnoRec(long long x){
    if(x==0)
        return 0;
    else
        return reverseofnoRec(x/10)*10 + x%10;
}
*/

long long base10conversionRec(long long x, long long base_x){
    if(x==0)
        return 0;
    else
        return base10conversionRec(x/10, base_x)*base_x + x%10;
}


// convert a no in base_x to a no in base_y
long long baseconversion(long long x, int base_x, int base_y){
    if(base_y == 10){
        return base10conversionRec(x,base_x);
    }

}

