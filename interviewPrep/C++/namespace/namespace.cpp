/* 
* Namespace definition doesn't terminate with a semicolon like a class definition.
* The namespace definition must be done at global scope or nested inside another namespace.
* You can use an alias name for your namespace name for ease of use.
* namespaces can be extended. A namespace definition can be continued and extended over multiple files they are
* not redefined or overridden.
 */

#include<bits/stdc++.h>

using namespace std;

namespace Myspace{
    int a;
    int fun();

    class A{
        public:
        void foo();
    };
}

namespace ms=Myspace;

int ms::fun(){
    cout<<"Executing fun of the namespace "<<endl;
}

void ms::A::foo(){
    cout<<"Executed foo"<<endl;
}

int main(){

    ms::fun();

    ms::A obj;

    obj.foo();

    return 0;
}