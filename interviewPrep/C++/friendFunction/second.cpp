/* Overloading of insertion and extraction operations. 

Things to remember:
    1. In the istream and ostream classes the extraction(>>) and insertion(<<) operator are overloaded. It would 
    have overloaded these operators for accepting primitive types.

    2. If we want to use these operators for our types then we will have to declare a friend function. We make 
    friend function for a class when we want to access the private members of the class through the objects. So
    if we want to print the private members of the Complex using cout then we should make a friend function of 
    the Complex class.

    3. 

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
        cout<<"a: "<<a<<" "<<"b: "<<b<<endl;
    }

    friend ostream& operator<<(ostream& ,  Complex);
    friend istream& operator>>(istream &din, Complex &c);
};

ostream& operator<<(ostream &dout, Complex c){
    //we can use cout or dout both are same thing reference of ostream type
    dout<<c.a<<" "<<c.b;

    return dout;
}

istream& operator>>(istream &din, Complex &c){
    din>>c.a>>c.b;
    
    return din;
}

int main(){
    Complex c1,c2;
    cout<<"Enter a complex no: ";
    cin>>c1;
    cout<<"Enter a complex no: ";
    cin>>c2;  
    //cin>>c1; cin is also an object and the extraction operator is overloaded in that class
    //cin.operator>>(c1); //another way of calling the >> operator using cin object
    cout<<c1<<"\n"; //using friend we can also call "operator<<(cout,c1);" is equivalent to "cout<<c1;"

    //? We can have cascading of operator like below
    cout<<c1<<"\n"<<c2<<"\n"; 
    //? In this case the LHS of the second << operator should also have the appropriate type. Here it should be 
    //? the type or class which cout belongs to which is ostream but we can't create the object of ostream so we 
    //? return reference (ostream&)


    return 0;
}