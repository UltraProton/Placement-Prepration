/* is-a relationship. E.g sports car is a car so sports car is a child class. 

* 1. Why to do public inheritance for isa relationship.
    1. Sports car definitely want's to have incrementGear() service. This public service of the base class will be public in the derived 
    class when we do public inheritance as the public member of base class becomes public in derived class in case of public inheritance.
    In case of protected inheritance the public and the protected both becomes protected in the derived class in which case the object of the
    derived class won't be able to access this service as the objects can't access the private and protected members directly.

* 2. When to do protected and private inheritance? 


*/

class Car{
    private:
    int gear;
    public:
    void incrementGear(){
        if(gear<5){
            gear++;
        }
    }
};

class sportsCar: public Car{
    private:

};

class Array{
    private:
    int a[10];
    public:
    void insert(int index, int value){
        a[index]=value;
    }
};

// class STACK: public Array{
//     int top;
//     public:
//     void push(int value){
//         insert(top,value);
//     }
// };


class STACK: private Array{
    int top;
    public:
    void push(int value){
        insert(top,value);
    }
};


int main(){
    STACK s1;
    s1.push(34);
    //If we do a public inheritance then the insert function can be called using the object of the derived class. But if you see the code
    //the next element must be inserted at the index 1 after pushing 34. But this is a violation of stack property here. So insert function
    //should not be accessible to STACK. So here we need to do a private or protected inheritance.
    
    //? s1.insert(5,56);

    
    return 0;
}