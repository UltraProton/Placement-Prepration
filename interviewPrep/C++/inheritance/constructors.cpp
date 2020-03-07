/*
? Very important 
* 1. We know that the constructor is invoked implicitly when an object is created.
* 2. In inheritance when we create object of the derived class what will happen ?
    ans. Whenever we create an object of child class then the memory for the parent class is also given. 
    Constructors main work is to initialize the members of the class. Parents constructor will initialize the
    members of the parent class and child class constructor will initialize the members of the child class but
    the child class has both the parent class members and child class members. So both the constructors must be
    called. 

*3. Compiler implicitly creates copy constructor , default constructor and assignment operator. 
 
 */
#include<bits/stdc++.h>

using namespace std;

class A{
    int a;
    public:
    /* A(){} */
    A(int k){
        a=k;
    }

    int getA(){
        return a;
    }

    ~A(){}
};

class B :public A{
    /* 
    
    B():A() { }
    
     */

    int b;

    public: 

    B():A(4) {};

    B(int x, int y) : A(x){ //This is the way to call the base class constructor using child class constructor
        b=y;
    }

    int getB(){
        return b;
    }

    ~B();
};

int main(){
    B obj;
    B obj1(2,3);

    cout<<obj1.getA()<<" "<<obj1.getB()<<endl;

    /* If we are making the object of the base class then the constructor of the base class will run. If we don't
     make any constructor. 
    ! Only child class constructor will call base class constructor. When compiler sees that you haven't made any 
    ! constructor in your derived class then compiler will create a default constructor in your class not only that 
    ! it will take the necessary step to call the base class constructor as well.

    ! So firstly the base class constructor will be called then the child class constructor will be called. So the
    ! order of execution of constructors is from base to derived. But the order of calling is from child to parent.

    ? Scenario: Let's say the base class has a parametrized constructor but the derived class don't have any constructor.
    * In this case the compiler will make a default constructor in the derived class and will try to call the base 
    * class default constructor but it won't find any default constructor in the base class because when we make our
    * own constructor other than the default constructor then compiler don't make any default constructor implicitly in
    * which case we will get error. If we don't have a default constructor in the base class then not only we will have to
    * make our own constructor in the derived class but also take care about calling the base class constructor with the 
    * appropriate arguments.
    * In case we forget to call the base class constructor then the compiler will implicitly call the base class default constructor
    * and if it doesn't find the base class default constructor because we made our own constructor then we will have an error.
     
    ? About Destructors:
    * In case of destructors first child destructor will execute its code and then parent's destructor will be executed. Its opposite to the
    * case of constructors where first parent's constructor will be executed and after that the child constructor gets executed. Destructor's
    * don't have any scope of arguments so here if we forget to create the destructor then compiler will automatically create a destructor with
    * empty body and even if we don't call the base class destructor then also the base class destructor will be called after finishing the 
    * child class destructor execution by the compiler.

     */

    return 0;

}