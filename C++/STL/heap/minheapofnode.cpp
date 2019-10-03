/* 

Here we will have min heap of user defined type.

 */

#include<bits/stdc++.h>

using namespace std;

class node{
    public:
    int key;
    int value;
    node(int k, int v): key(k), value(v){}
};

// //* We need to overload "<" operator so that priority queue can decide in which order the nodes will be placed in it
// bool operator<(const node &a, const node &b){
//     //* This will return true when a.value is less than b.value in which case the node with max value will be at the top of max
//     //* priority queue 
//     return a.value < b.value;
// }

//? To make it work like min heap we should do something like this
bool operator<(const node &a, const node &b){
    return a.value > b.value; //* If a.value is less than b.value then it will return false in which case the node with smaller
                              //* will have the higher priority then the node with higher value
} 

int main(int argc, char const *argv[])
{
    
    priority_queue<node> Q;
    
    Q.push(node(1,2));
    Q.push(node(2,3));
    Q.push(node(3,4));
    Q.push(node(4,5));
    Q.push(node(5,6));
    Q.push(node(6,6));

    while(!Q.empty()){
        cout<<Q.top().key<<" , "<<Q.top().value<<endl;
        Q.pop();
    }

    
    return 0;
}


