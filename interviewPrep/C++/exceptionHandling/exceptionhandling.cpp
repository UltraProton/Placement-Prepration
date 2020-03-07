/* 
* Any abnormal behaviour at runtime.
* When an exception is caught arg will receive its value.
* Any type of data can be caught including user defined class type.
* throw must be executed either within the try block or from any function that the code within the block calls.
 */

#include<bits/stdc++.h>

using namespace std;

// We can throw an exception in a function as well
void fun(){
    throw 10;
}

int main(){

    cout<<"Welcome"<<endl;

    int i=10;

    /*  
    * try and catch are compulsory to be written together. 
    * throw can be written without any try and catch. 
    * The type thrown and catch argument should be consistent. You can't throw an int and expect it to be caught
    * by a double. It will cause a runtime error.
    */

    try{
        if(i==1){
            throw "one";
        }

        if(i==2){
            throw 2;
        }

        if(i==3){
            throw 3.9;
        }

        if(i==10){
            fun();
        }
        
        cout<<"\nIn  try";
    }

    //* Usign elipsis we can catch different types of exception that are thrown i.e we don't need to worry about
    //* the type of the exception which is thrown
    // catch(...){
    //     cout<<"Exception caught using elipsis"<<endl;
    // }

    catch(int e){
        cout<<"\nException no: "<<e;
    }

    cout<<"\nLast line";
    
    return 0;
}