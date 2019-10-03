#include<bits/stdc++.h>

using namespace std;

void showVector(vector<int> &v){
    for(auto x: v)
        cout << x << " ";
    cout<<endl;
}



int main(){
    vector<int> v1{8,9,04,4,5,6,7,8,12};

    vector<int> v2(v1.size());

    //std::copy(v1.begin(), v1.end(), v2.begin());

    //show(v2);

    //vector<int> v3(10,8);

    //show(v3);

    //std::copy_n(v1.begin(), 5 /* n */, v3.begin());

    //show(v3);

    nth_element(v1.begin(), (v1.begin()+(v1.size())/2), v1.end());

    cout <<  v1[v1.size()/2] << endl;

    sort(v1.begin(), v1.end());

    showVector(v1);

    return 0;
}
