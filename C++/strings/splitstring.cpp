#include<bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    /* code */

    //Taking the space separated input
    string space_sep="";
    string delimeter1=" ";
    vector<int> result1;


    getline(cin,space_sep); 

    //cout<<space_sep<<endl;

    int pos=space_sep.find(delimeter1);

    while(pos!=string::npos){
        string curr="";
        curr= space_sep.substr(0,pos);
        //cout<<curr<<endl;
        result1.emplace_back(stoi(curr));
        space_sep.erase(0,pos+delimeter1.size());
        pos=space_sep.find(delimeter1);
    }

    result1.emplace_back(stoi(space_sep));

    
    for(auto x: result1){
        cout<<x<<endl;
    }

    cout<<endl;

    string comma_separated="";
    string delimeter2=",";
    vector<int> result2;

    getline(cin,comma_separated);

    pos=comma_separated.find(delimeter2);

    while(pos!=string::npos){
        string curr="";
        curr=comma_separated.substr(0,pos);
        result2.emplace_back(stoi(curr));
        comma_separated.erase(0,pos+delimeter2.size());
        pos= comma_separated.find(delimeter2);
    }

    result2.emplace_back(stoi(comma_separated));

    for(auto x: result2){
        cout<<x<<endl;
    }

    return 0;
}
