#include<bits/stdc++.h>

using namespace std;

bool anagrams(string &str1, string &str2);
bool anagrams_bit_man(string &str1, string &str2);

int main(int argc, char const *argv[])
{
    /* code */
    int n=0;
    string s1="";
    string s2="";
    cin>>s1>>s2;
    
    cout<<anagrams_bit_man(s1,s2)<<endl;
    
    return 0;
}

bool anagrams(string &s1, string &s2){
    vector<int> count(256,0);
    if(s1.size() != s2.size()){
        return false;
    }
    for(int i=0;i<s1.size() && i<s2.size();i++){
        count[s1[i]]++;
        count[s2[i]]--;
    }

    for(auto x: count){
        if(x!=0){
            return false;
        }
    }

    return true;

}

bool anagrams_bit_man(string &s1, string &s2){
    if(s1.size()!=s2.size()){
        return false;
    }

    int val=0;
    for(int i=0;i<s1.size();i++){
        val= val^s1[i];
        val=val^s2[i];
    }

    return val==0;
}