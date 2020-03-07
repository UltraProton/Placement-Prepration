#include<bits/stdc++.h>

using namespace std;

int main(){
    string str="adflkjadslfjad;lfkjd";
    cout<<str.substr(0,1)<<endl; // print the characters starting at pos 3 and upto len

    //string str1="\12090909\125\\";

    string str1 = ",120,ddafadf,0909";

 
    std::string delimiter = "\\";

    size_t pos = 0;
    std::string token;
    while ((pos = str1.find(delimiter)) != std::string::npos) {
        token = str1.substr(0, pos);
        std::cout << token << std::endl;
        str1.erase(0, pos + delimiter.length());
    }
    std::cout << str1 << std::endl;

    return 0;
}