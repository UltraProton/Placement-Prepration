#include<bits/stdc++.h>

using namespace std;

/*
! Below line may not be true...confirm it 
If we talk about a single class i.e no worry about inheritance then we have a parameterized constructor here. In this case there is no 
conflict and compiler will implicitly make default constructor , copy constructor and assignment operator. If we write any constructor then
compiler will NOT make the default constructor it is not true the other way if we write a default or parameterized constructor then 
compiler creates a copy constructor.
  */


class point{
    int x,y;
    public:
    point(int i=0, int j=0){
        x=i;
        y=j;
    }
    int getX(){
        return x;
    }
    int getY(){
        return y;
    }
};

int main(){
    point p1;
    point p2=p1;
    cout<<"x= "<<p2.getX()<<"y= "<<p2.getY()<<endl;

    return 0;
}