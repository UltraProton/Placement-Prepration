/* 
? Important questions:

1. Can a constructor be private in c++?
ans. 
    1. Using friend class
    Yes if we want the objects of the class should not be instantiated by any class but only by friend class. The objects of the class with 
    private constructors can be created inside the functions of friend class.



2. Imp points about constructor creation.
    1. If we don't create any constructor then there will be 2 constructors created by the compiler default constructor and copy constructor.
    2. If we create atleast one constructor then the default constructor will not be created but the copy constructor will be created by compiler.
    3. If we create the copy constructor then the copy constructor will obviously not be created by the compiler.
    4. //? The copy constructor should be created by reference of the object being passed to the copy constructor. 
        4.1 Whenever a object is created its constructor is called.
        4.2 If we pass an object as argument without reference then that argument will again call the COPY CONSTRUCTOR because when we pass
            an argument to the function the value is copied in the formal arguments.
    
 */


#include<bits/stdc++.h>

using namespace std;

class Complex{
    private:
    int re;
    int img;

    public:
    Complex(){};
    Complex(int re,int img);
    Complex(Complex &c1); //? Right way of creating the copy constructor
    
    /* Complex(Complex c1); It will cause infinite recursion because the object passed to this constructor will be copied to c1 which is done 
                            with the help of copy constructor. So it will cause infinite recursion.
                            */

};


int main(){
    Complex c1;
    Complex c2(c1); //Here copy constructor will be called

}