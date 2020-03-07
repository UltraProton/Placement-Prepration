#include<bits/stdc++.h>

using namespace std;
//
class Container{
    public:
    virtual double& operator[](int)=0;//pure virtual function
    virtual int size() const=0;//const member function
    virtual ~Container();
};

class Vector_Container :  Container{

};

int main(){

    return 0;
}