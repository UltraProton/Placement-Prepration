#include<bits/stdc++.h>

using namespace std;

void showVector(vector<int> &v){
    for(auto x: v)
        cout << x << " ";
    cout<<endl;
}


void showList(list<int> &lst){
    for(auto x: lst)
        cout << x << " ";
    cout << endl;
}

/*

If we want to sort in descending order we can make use of user defined function e.g
The value returned indicates whether the element passed as first argument is
considered to go before the second in the specific strict weak ordering it defines.

*/

int comp(int a,  int b){
    return (a > b); // It is another way of saying that 'a' goes before 'b' if (a > b)
}

int main(void){
    int arr[]= {9,4,3,210,11,345,0,-123};

    vector<int> v={9,4,3,210,11,345,0,-123};

    list<int> lst= {9,4,3,210,11,345,0,-123};

    // Printing the largest element using nth_element()
    std::nth_element(v.begin(), v.begin()+1, v.end(), greater<int>());

    cout << *(v.begin()) << endl;


    // Sort the array
    sort(arr, arr+8);

    cout << "array" << endl;
    for(int i=0; i <8; i++)
        cout<< arr[i] << " ";

    cout<< endl;

    sort(v.begin(), v.end());

    // sorting a list has its own class member function sort()
    lst.sort();

    showVector(v);
    showList(lst);

    // learning partial sort
    vector<int> v1= {-9,8,7,6,10,11,56,-9, 0,4,4};

    // Remember in partial_sort() the range is [first, end)
    partial_sort(v1.begin(), v1.begin()+2 ,v1.end());

    showVector(v1);

    //nth_element()

    // sorting a collection in descending order can be done using std::sort() by passing greater<T>() function as third arg in sort
    sort(v1.begin(), v1.end(), greater<int>());

    showVector(v1);

    sort(v1.begin(), v1.end());

    showVector(v1);

    // you can write your own comparator function to sort it
    sort(v1.begin(),v1.end(), comp);

    showVector(v1);

    /* nth_element() will place at the nth position in collection the element had the collection been sorted i.e
    the collection is rearranged such that elements at position < n are <= nth element and the elements
    at position greater than n are > nth element */

    vector<int> v2= {-10,11,13,15,80,-34,67,10};

    nth_element(v2.begin(), v2.begin()+4, v2.end());

    showVector(v2);

    /* we can use the concept of comp() function here as well...in that case the array the nth element will be at its correct position had the element being
     sorted in descending order. */

    //nth_element(v2.begin(), v2.begin()+4, v2.end(), greater<int>());

    //showVector(v2);


    /* The nth_element is very very powerful tool to have e.g
     Prob1: find the first 3 largest element in a collection
     Prob2: find the first 3 smallest element in a collection */

  // Prob1: We can use nth_element() to put the correct element at 4th position and print the first three elements in the collection after that


    vector<int> v4= {0,12,-10,3,4,5,7,9,45};

    /*
    nth_element(v4.begin(), v4.begin()+3, v4.end(), greater<int>());

    cout << endl;

    for(int i=0;i<3;i++)
        cout << v4[i] << " ";

    // Prob2:

    nth_element(v4.begin(), v4.begin()+3,v4.end());

    cout << endl;

    for(int i=0;i<3;i++)
        cout << v4[i] << " ";

    */

    //partial_sort(v4.begin(), v4.begin()+3, v4.end());

    showVector(v4);

    // Finding the largest element using partial_sort()

    partial_sort(v4.begin(), v4.begin()+1, v4.end(), greater<int> ());

    cout << *(v4.begin()) << endl;

    showVector(v4);

    return 0;

}
