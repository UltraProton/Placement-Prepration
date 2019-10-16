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

    /*

    vector<int> v={1,2,3,4,5,6,7,8,9};

    // makes heap out of a collection
    std:: make_heap(v.begin(),v.end());

    cout <<"value at location pointed by v.end()-2:  "<<  *(v.end()) << endl;

    // To insert a new element in a heap push the element in the collection and use std::push_heap() to insert it at the
    // correct position in the heap
    v.push_back(15);
    std:: push_heap(v.begin(), v.end()); //pushes the last element in the collection at its correct position in heap

    show(v);

    // std::pop_heap() swaps the root and the last element in heap and then maintain the heap property without considering the last element
    std:: pop_heap(v.begin(), v.end());

    int max= v.back();

    cout <<  max << endl;

    v.pop_back();

    show(v);

    // sorting a heap using heap's pop_heap() function
    int i=0;

    for(auto it = v.begin(); it!=v.end(), i < v.size() ; it++, i++){
        std:: pop_heap(v.begin(),(v.end()-i));
        show(v);
    }

    //cout << i << endl;

    //show(v);

    */

    vector<int> v2{9,04,5,45,98};

    make_heap(v2.begin(),v2.end());

    show(v2);

    sort_heap(v2.begin(), v2.end());

    show(v2);

    return 0;
}

