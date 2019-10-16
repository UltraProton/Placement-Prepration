#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    //allocating dynamic memory
    // To a variable:
    int *x= new(nothrow) int;
    *x=5;
    cout <<*x <<endl;

    // Allocating block of memory
    int *arr= new(nothrow) int[10] {0};

    if(!arr)
        cout << "Memory not available" << endl;
    else{

        for(int i=0; i <10; i++)
            cout<< arr[i] <<endl;
        }

    delete[] arr;
    delete x;

    return 0;
}
