/* 

! The parameterized constructor of base class cannot be called in the default constructor of sub class it should be called in the 
! parametrized constructor of the child class.
 */

#include<bits/stdc++.h>

using namespace std;

class P{
    int b;
    public:
    // P(){
    //     cout<<"Parents constructor\n";
    // }

    // P(int x){

    // }
};

class C:public P{
    public:
    int a;
    
    // C(){}; //Even if you don't create this constructor it will be implicitly created by the compiler to call base class default constructo

    C(int x){ //If the base class don't have a default constructor because we created our own parameterized constructor then it will give an error
        a=x;
    };
};


int main(){
    //C obj;
    C obj(1);
    cout<<obj.a<<endl;
    return 0;
}