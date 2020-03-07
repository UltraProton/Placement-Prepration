/* 
Class type to class type conversion
Here the conversion can be done 2 ways:
    * Conversion through constructor. 
    * Conversion through casting operator.
    * If we want to solve it using constructor then the constructor will be created in the class which is at the 
    * lhs of the assignment operator. In case of casting operator the operator will be defined in the class which
    *  is at the rhs of the assignment operator.
    *  */

#include<bits/stdc++.h>

using namespace std;

class Item{
    int a, b;
    public:
    void showData(){
        cout<<"a "<<a<<","<<"b "<<b;
    }

    Item(){}

    Item(int x, int y){
        a=x;
        b=y;
    }

    //Using the constructor
    // Item(Product p){
    //     a=p.getM();
    //     b=p.getN();
    // }
};

class Product{
    int m ,n;
    public:
    void setData(int x, int y){
        m=x;
        n=y;
    }

    int getM(){
        return m;
    }

    int getN(){
        return n;
    }

    // Using casting operator
    operator Item(){
        Item i(m,n);
        return i;
    }
    
};


int main(){
    Item i1;
    Product p1;
    p1.setData(3,4);
    i1=p1;
    i1.showData();
    return 0;
}