/* 
Constructors can be private. But they will be called in the following ways:
 
 */

#include<bits/stdc++.h>

using namespace std;

// Using friend class, here we want the objects to be instantiated only by the friend class.

//class B;
class A{
    private:
    A(){
        cout<<"Constructor of A\n";
    }
    friend class B;
};

class B{
    public:
    B(){
        A a1;
        cout<<"Constructor of B\n";
    }
};

int main(){
    B b;
    
    return 0;
}