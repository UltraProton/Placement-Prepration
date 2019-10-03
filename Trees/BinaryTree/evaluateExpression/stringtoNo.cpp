#include<bits/stdc++.h>

using namespace std;

int convert(string &s);

int main(int argc, char const *argv[])
{
    string s="8977";

    cin>>s;

    cout<<convert(s)<<endl;

    return 0;
}


int convert(string &s){
    int ans=0;
    for(auto x:s){
        ans= ans *10 + x-'0';
    }

    return ans;
}
