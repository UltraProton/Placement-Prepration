#include<bits/stdc++.h>

using namespace std;

int edit_dist(const string &str1, const string &str2, int m, int n);

int main(int argc, char const *argv[])
{
    /* code */
    string str1="abcdef";
    string str2="acf";

    cout<<edit_dist(str1,str2,str1.size(),str2.size())<<endl;

    return 0;
}


//all the changes are considered in string 1 in our method

int edit_dist(const string &str1, const string &str2,int m, int n){
    if(m==0){
        return n;
    }

    if(n==0){
        return m;
    }

    if(str1[m-1]==str2[n-1]){
        return (edit_dist(str1, str2,m-1,n-1));
    }

    else {
        return 1+ 
                ( min(edit_dist(str1,str2,m-1,n),//remove..if we removed a char from str1 then we should go to next part of str1
                  min(edit_dist(str1,str2,m,n-1),//insert..if we inserted the char in str1 then we have handled nth char in str2 so move one backward in str2
                  edit_dist(str1,str2,m-1,n-1))) //replace..if replacement is done then we must move further in both the strings
                );
    }
}
