#include<bits/stdc++.h>

using namespace std;

int LPSubSeq(string s,int l,int r);

int main(){
    string str="abacbb";

    cout<<LPSubSeq(str,0,str.size()-1)<<endl;

    return 0;
}

int LPSubSeq(string s,int l,int r){
    if(l>r){
        return 0;
    }
    if(l==r){
        return 1;
    }

    if(s[l]==s[r]){
        return 2+ LPSubSeq(s,l+1,r-1);
    }

    else{
        return std::max(LPSubSeq(s,l,r-1),LPSubSeq(s,l+1,r));
    }
}