#include<iostream>

using namespace std;

class Complex{
    private:
    int a, b;
    
    public:
    Complex(){}
    Complex(int k){
        a=k;
        b=0;
    }

    void setData(int x, int y){
        a=x;
        b=y;
    }

    void showData(){
        cout<<a<<" , "<<b<<" ";
    }

    operator int(){
        return a;
    }
};

int main(){
    Complex c1;
    int x=5;
    
    float y=x; //automatic type conversion
    
    x=y; //automatic type conversion

    //? Primitive to class type
    c1=x;  
    /* c1.Complex(x) i.e appropriate constructor is called when we assign an integer to a class type this is a 
    new thing where we can implement primitive type to class type using the constructor. So here x is passed as 
    argument to the constructor when we do the assignment of a primitive type to class type.
    */  
    
    c1.showData();


    //? Class type to primitive type can be done with the help of casting operator
    Complex c2;
    c2.setData(3,4);
    x=c2; //x=c2.operator int();

    cout<<x<<endl;

    return 0;

}