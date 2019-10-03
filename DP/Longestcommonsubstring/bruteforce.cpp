#include<bits/stdc++.h>

using namespace std;

string lc_substr(string &s1, string &s2);

int main(int argc, char const *argv[])
{
    string s1="abc";
    string s2="bc";

    cout<<lc_substr(s1,s2)<<endl;
    
    return 0;
}

/* 
    ! O(m^2) substrings of first string and to check whether one string is substring of another it requires O(n) time
    ! So overall O(m^2 * n)

 */
string lc_substr(string &s1, string &s2){
    int max_len=INT_MIN;
    int start_idx=-1;
    for(int i=0;s1[i]!='\0';i++){  
        for(int j=i;j<s1.size();j++){
            cout<<s1.substr(i,j-i+1)<<endl;
            //If we have are considering a bigger string then the string s2 then no point in searching in s2
            if(j-i+1 > s2.size()){
                continue;
            }
            if(s2.find(s1.substr(i,j-i+1))!=string::npos){
                //cout<<'x'<<endl;
                if(j-i+1 > max_len){
                    max_len=j-i+1;
                    start_idx=i;
                }
            }
        }
    }

    cout<<start_idx<<endl;
    cout<<max_len<<endl;

    return s1.substr(start_idx,max_len);
}
