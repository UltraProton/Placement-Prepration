#include<iostream>
#include<algorithm>

using namespace std;

void show(vector<int> &);

int main(){
    vector<int> v1= {1,3,5,6,7,8,90};

    vector<int> v2= {-78,1,45,67,78};

    vector<int> v3(v1.size()+v2.size());

    inplace_merge(v1.begin(),v1.end(), v2.begin(), v2.end(),v3.begin());

    show(v1);
    show(v2);
    show(v3);

    return 0;

}

void show(vector<int> &x){
    for(auto p: x)
        cout<< p<< " ";
    cout << endl;
}
