/* 

When to use the initializer list ?
 */

#include<bits/stdc++.h>

using namespace std;

//Case 1: To initialize the non-static data members because no memory is allocated to const data members
class P1{
    public:
    P1():a(5){}

    private:
    const int a;
};

class C1{
    public:

    private:
    int b;
};

//case 2: For initialization of member objects which do not have a default constructor
class P2{
    private:
    int a;
    public:
    //It doesn't have a default constructor because we have created our own parameterized constructor
    P2(int x){
        a=x;
        cout<<"P2's constructor called\n";
    }

};



//! Note that here we are not inheriting P2
class C2{
    private:
    //P2 obj(4); //This will give error
    P2 obj;
    public:
    C2(int );
};

//So here you have given memory to the object member using the constructor of child class
C2::C2(int x):obj(x) { cout<<"C2 constructor called\n"; }

int main(){
    C2 obj(10);
    return 0;
}

//Case 3 : For initialization of base class members. If you see the above example we have passed the value to the base class constructor
//through the object but we can also do that by directly calling the base class constructor

class P3{
    private:
    int a;
    public:
    //It doesn't have a default constructor because we have created our own parameterized constructor
    P3(int x){
        a=x;
        cout<<"P2's constructor called\n";
    }

};


class C3:public P3{
    private:
    public:
    C3(int );
};

//So here you have given memory to the object member using the constructor of child class
C3::C3(int x):P3(x) { cout<<"C3 constructor called\n"; }

int main(){
    C2 obj(10);
    return 0;
}



