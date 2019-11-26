/*
1. Friend function is not a member function.
2. It must be declared insided the class but defined outside the class.
3. It can access all the members of the class through object.
4. It has no caller object.
5. It should not be defined with membership label.

  */

#include<bits/stdc++.h>

using namespace std;

class Complex{
    private:
    int a, b;

    public:
    void setData(int x, int y){
        a=x;
        b=y;
    }
    void showData(){
        cout<<a<<" "<<b<<endl;
    }

    friend void fun(Complex c){
        cout<<c.a<<" "<<c.b<<endl;
    }
};

/* 
1. Friend function can be made friend of different classes.
2. Friend should be private or public? 
   ? Friend function is not a member function so you can declare it anywhere in the class it doesn't matter.

* Advantages of friend functions:
    1. We can access the private members of 2 different class simultaneously with the help of common friend function of the 2 classes.
    2.  

*/

//forward declaration
class B;
class A{
    private:
    int a;
    
    public:
    A(int x):a(x){};
    friend void fun(A,B);
};

class B{
    private:
    int b;

    public:
    B(int x):b(x){}
    friend void fun(A,B);
};
//We will access the private members of 2 different class simultaneously
void fun(A o1,B o2){
    cout<<"Sum is "<<o1.a+o2.b<<endl;
}


int main(){
    A o1(1);
    B o2(2);

    fun(o1,o2);

    return 0;
}