#include<bits/stdc++.h>

using namespace std;

int main(){
    vector<pair<int,int>> v;
    v= vector<pair<int,int>>(10, std::make_pair(-1,-1));

    for(auto x:v){
        cout<<x.first<<" "<<x.second<<endl;
    }
    return 0;
}