/* 
By default a copy constructor and an implicit copy assignment operator is created by the compiler.

! Deep copy is necessary when there is pointer in the object accessing an outside resource. 
! In which case we should make our own copy constructor.
 

 */

#include<bits/stdc++.h>

using namespace std;

class Dummy{
    private:
    int a;
    int b;
    int *p;

    public:
    
    Dummy(){
        p=new int;
    }

    void setData(int x, int y, int z){
        a=x;
        b=y;
        *p=z;
    }

    void showData(){
        cout<<"\na: "<<a<<"b: "<<b;
    }

    /* The default copy constructor which is implicitly created by the compiler 
    
    Dummy(Dummy &d){
        this.a= d.a;
        this.b=d.b;
        this.p=d.p;
    }

    So in the above case shallow copy will be done so it becomes our responsibility to make our own constructor.

     */

    Dummy(Dummy &d){
        this->a=a;
        this->b=b;
        p= new int;
        *p=*(d.p);
    }

    /* 
    * If there was a shallow copy then at the time when destructor is called the memory pointed by the pointer 
    * will be released which will result in other pointer variables of the objects pointing to a memory which is 
    * freed and cause it to become dangling pointer. 
     */

    ~Dummy(){
        delete p;
    }

};


int main(){
    Dummy d1;
    d1.setData(2,3,4);

    Dummy d2=d1; // Here copy constructor will be called and shallow copy of the member variables will be done


}