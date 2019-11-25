#include<bits/stdc++.h>

using namespace std;

class Vector{
    private:
    double *elem;
    int sz;

    public:
    //Assumming s is never <0
    Vector(int s):elem{new double[s]},sz{s}{
        //initializing elements
        for(int i=0;i<s;i++){
            elem[i]=0;
        }
    }
    //destructor
    ~Vector(){ delete[] elem; };
    //access operator
    double & operator[](int i);
    //returns the size of Vector
    int size() const;
};



int main(){

}