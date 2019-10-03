#include<iostream>
#include<algorithm>

using namespace std;

void show(vector<int> &);

int product(int x, int y){
    return x*y;
}

int main(void){
    vector<int> v={9,4,5,1,8,8,9};
    int sum=1;

    /*

    cout <<"sum: "<< accumulate(v.begin(), v.end(), sum) << endl;

    cout << "product:" << accumulate(v.begin(),v.end(), sum, product) << endl;

    cout << "Subtraction: " << accumulate(v.begin(), v.end(), sum, std::minus<int>()) << endl;

    // Note that the value of sum variable is not changed during the operation

    */

    // partial_sum() is yet another very useful method

    vector<int> v1{1,2,3,4,5,6};

    vector<int> v2(v1.size());

    partial_sum(v1.begin(), v1.end(), v2.begin());

    show(v2);

    // partial_sum() using own function which performs a specific task

    partial_sum(v1.begin(), v1.end(), v2.begin(), product);

    show(v2);

    return 0;
}


void show(vector<int> &x){
    for(auto p: x)
        cout<< p<< " ";
    cout << endl;
}
