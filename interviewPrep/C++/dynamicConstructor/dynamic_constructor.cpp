#include<bits/stdc++.h>

using namespace std;

class A{
    private:
    int a, b;
    int *p;

    public:
    A(){
        a=0;
        b=0;
    }

    /* This is a dynamic constructor. The memory to the pointer is allocated by the constructor which is why it
    is called dynamic constructor. Dynamic constructor doesn't give memory to object but it allocates the memory
    to be accessed by the member variable of the object and the memory is allocated during constructor execution.
     */
    A(int x, int y, int z){
        a=x;
        b=y;
        p=new int;
        *p=z;
    }
};


int main(){
    A o1,o2,o3(3,4,5);

}