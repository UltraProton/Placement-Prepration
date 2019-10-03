#include<algorithm>
#include<iostream>
#include<stdlib.h>
#include<set>

using namespace std;

void showSetofPairs(set<pair<int,int>> s){
    for(auto x: s)
        cout <<"[" << x.first << ',' << x.second << ']'<< endl;
    cout << endl;
}

void pointPresent(int point){
    set<pair<int,int>> s;

    s.insert({4,5});
    s.insert({6,20});
    s.insert({17,25});

    showSetofPairs(s);

    // Notice that in std::set upper_bound() is a member function
    set<pair<int,int>> :: iterator it= s.upper_bound({point,INT_MAX});

    /*
     Corner case: If we didn't use {point, INT_MAX} and used something like {point , INT_MIN} then in case first
     first value is same in both the comparisons then upper_bound() will compare the second value if the second value is
     smaller it will say this interval is upper bound and we go one step back and do the comparisons and the algorithms fails
     terribly

     */

    cout << "upper bound returned: [" << (*it).first << ',' << (*it).second << ']' << endl;

    // going one step back
    it--;

    pair<int,int> current= *it;

    if(current.first <= point && current.second >= point)
        cout << "Yes point is present in interval: [" << current.first << ',' << current.second << "]" << endl;
    else
        cout << "Not present"<< endl;
}

int main(void){

/*
    set<int> s;

    // In sets elments are always arranged in ascending order
    s.insert(9);
    s.insert(10);
    s.insert(-1);

    for(auto x: s)
        cout<<x<<" ";
    cout<<endl;

    // trying stuff
    set<int> :: iterator it;
    for(it=s.begin();it!=s.end();it++)
        cout<<*it<<" ";

    // s.find() returns an iterator to the element we are finding in the set if it can't find it then it returns s.end()
    auto it1= s.find(-1);
    auto it2= s.find(908098);

    if(it1==s.end())
        cout<< "Element not present"<< endl;
    else
        cout << *it1<< endl;

    if(it2==s.end())
        cout<< "Element not present" << endl;
    else
        cout<< *it2<< endl;

    // lets try upper bounds and lower bounds on set
    auto it3= s.lower_bound(-1);
    auto it4= s.upper_bound(2);

    if(it3==s.end())
        cout << "couldn't find something like that"<< endl;
    else
        cout << *it3<< endl;

    if(it4==s.end())
        cout<< "couldn't find something like that"<< endl;
    else
        cout<< *it4<< endl;
*/
    pointPresent(7);

    return 0;
}

