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
    //default constructor
    Complex(){ a=0; b=0;}
    //parameterized constructor
    Complex(int re, int img):a{re}, b{img} {}
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

    //We can also do operator overloading with the help of friend functions the logic will be same but the syntax
    // will be different
    //? Since this is a friend function it can't be defined inside the class but normal operator overloading can 
    //? be defined inside the class also. Recall that we need only one operand in case of normal operator 
    //? overloading as it is a member function and the left hand operand becomes the caller object.
    
    friend Complex operator+(Complex c1, Complex c2); 

    //* unary operator overloading as friend function
    friend void operator-(Complex &);
};

Complex operator+(Complex c1, Complex c2){
    Complex temp;
    temp.a= c1.a + c2.a;
    temp.b= c1.b + c2.b;
    return (temp);
}

void operator-(Complex &c){
    c.a=-c.a;
    c.b=-c.b;
}

/* 
Friend functions things to remember:
    1. Friend function can be made friend of different classes.
    2. Friend should be private or public? 
    ? Friend function is not a member function so you can declare it anywhere in the class it doesn't matter.
    3. If we do operator overloading using friend function then the no of arguments will be 1 more than the no of 
    arguments required when we do the operator overloading as member function of the class.
3. 

* Advantages of friend functions:
    1. We can access the private members of 2 different class simultaneously with the help of common friend function 
    of the 2 classes.
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

//We will access the private members of 2 different class simultaneously with the help of the objects of the class
void fun(A o1,B o2){
    cout<<"Sum is "<<o1.a+o2.b<<endl;
}


int main(){
    A o1(1);
    B o2(2);

    A o3(5);

    // cout<<o3.a; will give error because 'a' is private member of the class but this private member can be 
    // accessed by the object of the class inside the friend function.

    fun(o1,o2);

    Complex c(1,2);
    -c;
    c.showData();
    return 0;
}