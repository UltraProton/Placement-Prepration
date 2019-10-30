#include<bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    string str="";
    getline(cin,str);
    char arr[str.size()];
    for(int i=0;i<str.size();i++){
        arr[i]=str[i];
        cout<<arr[i];
    }
    
    return 0;
}
