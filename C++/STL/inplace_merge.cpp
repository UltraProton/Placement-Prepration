#include<iostream>
#include<algorithm>

using namespace std;

void show(vector<string> &);

int main(){

    /*
    vector<int> v1= {1,3,5,6,7,8,90};

    vector<int> v2= {-78,1,45,67,78};

    vector<int> v3(v1.size()+v2.size());

    // merges 2 containers and copy it to a 3rd container
    merge(v1.begin(),v1.end(), v2.begin(), v2.end(),v3.begin());

    show(v1);
    show(v2);
    show(v3);

    //  returns true if first sorted container contains second sorted container
    cout << includes(v3.begin(),v3.end(), v1.begin(),v1.end()) << endl;

    vector<int> v4(v1.size()+ v2.size());

    copy(v1.begin(),v1.end(), v4.begin());

    copy(v2.begin() ,v2.end(), v4.begin()+v1.size());

    show(v4);

    // so you can sort the array using inplace_merge() by first copying the 2 containers in a 3rd container...
    inplace_merge(v4.begin(), v4.begin()+v1.size(), v4.end());

    show(v4);

    */

    /* .............Set Functions on containers.................*/

    /*
    string str1= "Aditya Kumar, Machine Learning Lead at Google AI .";

    string str2= "CNN: Aditya (ML at Google AI) says Machine Learning is making progress in AI field each day.";

    string str4= "Aditya";

    string str3=" ";

    vector<char> p;

    // containers must be sorted for set functions to work
    sort(str1.begin(), str1.end());
    sort(str2.begin(), str2.end());

    auto it1= set_difference(str1.begin(), str1.end(), str4.begin(), str4.end(), p.begin());

    cout <<"Set difference: "<< endl;

    show(p);

    */

    vector<string> a{"Aditya", "Machine Learning", "Google AI", "Lead"};
    vector<string> b{"CNN", "Machine Learning","Progress", "Transformation"};

    // allocating memory to the destination container is very important before applying set_difference
    vector<string> c(a.size()+ b.size());

    sort(a.begin(),a.end());
    sort(b.begin(), b.end());

    cout << "Set a: " << endl;
    show(a);

    cout << "Set b: " << endl;
    show(b);

    auto it1= set_difference(a.begin(), a.end(), b.begin(),b.end(),c.begin());

    cout <<"Set Difference:" <<endl;
    show(c);

    vector<string> d(a.size()+ b.size());

    set_symmetric_difference(a.begin(),a.end(), b.begin(), b.end(), d.begin());

    cout<< "Symmetric Difference: " <<endl;
    show(d);

    vector<string> e(a.size()+ b.size());

    set_union(a.begin(),a.end(), b.begin(),b.end(), e.begin());

    cout<<"Set union: " << endl;
    show(e);

    vector<string> f(a.size()+ b.size());

    set_intersection(a.begin(),a.end(), b.begin(), b.end(), f.begin());

    cout<< "Set intersection: " << endl;
    show(f);

    return 0;

}

void show(vector<string> &x){
    for(auto p: x)
        cout<< p<< " ";
    cout << "\n\n\n";
}
