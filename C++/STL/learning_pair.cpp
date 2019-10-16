#include<iostream>
#include<utility>
#include<vector>
#include<algorithm>

using namespace std;

bool comparator(const pair<int,int> &p1, const pair<int,int> &p2){
    return (p1.second > p2.second);
}


int main(void){

    // pair is defined in utility header
    pair<int,char> pair1;

    pair1.first= 100;
    pair1.second = 'A';

    cout << pair1.first << pair1.second << endl;

    pair<int,char> pair2(3,'L');

    pair<int, char> pair3(pair2);

    cout << pair2.first << pair2.second << endl;

    //another way of initializing a pair here you don't need to mention the types
    auto p4 = make_pair(1,'g');

    cout << p4.first << p4.second<< endl;

    pair<int, int> p1= make_pair(1,90);
    pair<int,int> p2= make_pair(4,9);

    cout << (p1==p2) << endl;
    cout << (p1!=p2) << endl;

    // <= , < (logical) operators give result by comparing the first value of the pair only
    cout << (p1<=p2) << endl;
    cout << (p1 < p2)<< endl;
    cout << (p1 > p2) << endl;

    // swap function for pair
    cout << "Pair 1 before swapping: ["<< p1.first<< ","<< p1.second<< "]"<< endl;

    p1.swap(p2);

    cout << "Pair 1 after swapping: [" << p1.first << ',' << p1.second << "]" << endl;
    cout << "Pair 2 after swapping: [" << p2.first << ',' << p2.second << "]" << endl;

    // sorting an array of vectors based on the first element

    int arr1[]={2,5,-1,8,9};
    int arr2[]= {1,9,0,5,6};

    vector<pair<int,int>> v;

    for(int i=0;i<5;i++){
        v.push_back(make_pair(arr1[i], arr2[i]));
    }

    // sort is used to sort array or vectors in cpp
    sort(v.begin(), v.end());

    for(auto ele: v){
        cout<< ele.first << "," << ele.second << endl;
    }

    /* sorting in your defined order say decreasing order based on the second element of pair */
    sort(v.begin(), v.end(),comparator);

    for(auto ele: v){
        cout<< ele.first << "," << ele.second << endl;
    }

    return 0;
}


