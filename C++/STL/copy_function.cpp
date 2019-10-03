#include<algorithm>
#include<iostream>

using namespace std;

void show(vector<int> &);

int main(){
    vector<int> v1{8,9,04,4,5,6,7,8,12};

    vector<int> v2(v1.size());

    std::copy(v1.begin(), v1.end(), v2.begin());

    show(v2);

    vector<int> v3(10,8);

    show(v3);

    std::copy_n(v1.begin(), 5 /* n */, v3.begin());

    show(v3);

    return 0;
}

void show(vector<int> &x){
    for(auto p: x)
        cout<< p<< " ";
    cout << endl;
}
