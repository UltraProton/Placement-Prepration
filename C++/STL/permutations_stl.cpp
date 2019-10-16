#include<bits/stdc++.h>

using namespace std;

int main(){
    string str1("Aditya Bharti");
    string str2= "Himanshu Bharti";
    //string str3(5,'#');

    /*
    //cout <<str3 << endl;

    // rotate() rotates the container by specified positions to the left
    // notice: rotate() takes an iterator to the element uptil which we want to rotate
    std:: rotate(str1.begin(),str1.begin()+3,str1.end());

    cout << str1 << endl;

    // right rotation can be done using left rotate
    rotate(str2.begin(), str2.end()-3, str2.end());

    cout << str2 << endl;

  */

  /*

    // shuffle() in cpp
    unsigned seed=0;

    cout <<str1 << endl;

    shuffle(str1.begin(), str1.end(), default_random_engine(seed));

    cout <<str1 << endl;

    */

    // permutations
    string str3= "abcd";

    //sort(str3.begin(), str3.end());
    cout << str3 << endl;

    for(int i=0; i < 16; i++){
        next_permutation(str3.begin(), str3.end());
        cout <<str3 << endl;
    }

    prev_permutation(str3.begin(),str3.end());
    cout <<str3 << endl;

    // reverse() in cpp
    reverse(str3.begin(),str3.end());
    cout <<str3 << endl;

    return 0;
}
