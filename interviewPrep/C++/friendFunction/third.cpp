/* 
Friend class : If we want to make EVERY function of a class A as friend of another class B then we should declare
class A as friend of class B.
 */
#include<bits/stdc++.h>

using namespace std;

class A{
    public:
    void fun(){}
    void foo(){}
};

class B{
    //We can make every function of class A as friend of class B using scope resolution operator
    // friend void A::fun();
    // friend void A::foo();

    //But its better to make class A as friend of class B like below
    friend class A;
};

int main(){

}