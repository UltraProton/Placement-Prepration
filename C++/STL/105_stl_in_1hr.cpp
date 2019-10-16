#include<vector>
#include<stdlib.h>
#include<algorithm>
#include<iostream>

using namespace std;

void show(vector<int> &x){
    for(auto p: x)
        cout<< p<< " ";
    cout << endl;
}

int main(void){
    vector<int> v={1,2,3,4,5,6,7,8,9};

    // makes heap out of a collection
    std:: make_heap(v.begin(),v.end());

    // To insert a new element in a heap push the element in the collection and use std::push_heap() to insert it in the heap
    v.push_back(15);
    std:: push_heap(v.begin(), v.end()); //pushes the last element in the collection at its correct position in heap

    show(v);

    // std::pop_heap() swaps the root and the last element in heap and then maintain the heap property without considering the last element
    std:: pop_heap(v.begin(), v.end());

    int max= v.back();

    cout <<  max << endl;

    v.pop_back();

    show(v);

    return 0;
}

