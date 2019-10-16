#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;

struct data{
    int x;
    int y;
};

bool compare(data one , data two){
    return (one.x < two.x);
}

int main(void){
    vector<int> v{56,567,67,32,5,1,3434,56,656};

    sort(v.begin(), v.end());

    // way 1 of printing the vector
    for(auto x: v)
        cout << x <<" ";
    cout << endl;
    // way 2 of printing the vector
    for(auto x = v.begin(); x!= v.end();x++)
        cout << *x << " ";

    cout << endl;

    v.push_back(100);
    v.push_back(454);

    for(auto x: v)
        cout << x <<endl;

    // sorting vector of structs
    vector<data> v1{{1,3},{4,6},{9,8},{3,6}};

    sort(v1.begin(), v1.end(),compare);

    for(auto p: v1)
        cout << "[" << p.x <<","<<p.y <<"]" <<" ";

    return 0;

    //sorting a vector of pairs


}
