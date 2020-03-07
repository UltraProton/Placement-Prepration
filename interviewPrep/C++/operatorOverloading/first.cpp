/* 
? Important questions:

1. Can a constructor be private in c++?
ans. 
    1. Using friend class
    Yes if we want the objects of the class should not be instantiated by any class but only by friend class. The objects of the class with 
    private constructors can be created inside the functions of friend class.



2. Imp points about constructor creation.
    1. If we don't create any constructor then there will be 2 constructors created by the compiler default constructor and copy constructor.
    2. If we create atleast one constructor then the default constructor will not be created but the copy constructor will be created by 
    compiler.
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

    /* 
     ? Binary operator things to remember:
        1. The left hand operand of the binary operator is the caller object.
    */

    //Find out how to define this function outside of the class. Remember this is a normal function with name "operator+"
    Complex operator+(Complex c){
        Complex temp;
        temp.img = img + c.img;
        temp.re=   re  + c.re;
        
        return temp;
    }

    /* 
    ? Unary operator things to remember:
        1. 
     */

    void operator-(){
        this->re=-re;
        this->img=-img;
    }

    /* 
    ! Destructors
        1. They are called when the object goes out of scope or just before the object is going to be destroyed.
        2. Used to avoid memory leaks.
     */

    void show_data();

    ~Complex(){}
};


int main(){

    //int a= "afladkjfk";

    Complex c1,c4,c5,c2;

    Complex c3(2,3);
    c1= Complex(1,4);

    c2=Complex(c1); //Here copy constructor will be called

    //Remember: The left hand operand of the overloaded operator is the caller object
    c4= c1+c2; //? This is one of the way to call the overloaded operator
    c5= c1.operator+(c2); //? This is the other way

    //Example with the unary overloaded operator
    //c5.operator-();
    -c5; //One way of calling unary operator
    c5.show_data();

    Complex c6(4,7);

    c6.operator-(); //This is another way of calling overloaded unary operator member function

    return 0; 
}

Complex::Complex(int re, int img){
    this->re= re;
    this->img=img;
}

Complex :: Complex(Complex &c){
    re= c.re;
    img= c.img;
}


void Complex::show_data(){
    cout<<this->re<<" "<<this->img<<endl;
    //cout<<re<<" "<<img<<endl;


}

