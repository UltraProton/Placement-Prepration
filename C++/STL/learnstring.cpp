#include <iostream>
#include <string>

using namespace std;

int main(void){

/*    string s;

    cout <<"enter string: " <<endl;

    getline(cin,s);

    s.push_back('a');
    s.push_back('b');

    cout << "Initial string is: " << s <<endl;

    s.push_back('c');

    s.pop_back();

    cout << "String: " << s <<endl;

    cout <<"capacity: " <<s.capacity() <<endl;

    s= "geeksforgeeks";

    std:: string :: iterator it;
    std ::string :: reverse_iterator it1;

    cout << "string using iterator: " <<endl;

    for(it= s.begin(); it != s.end(); it++)
        cout << *it ;
        cout <<endl;

    cout <<"string using reverse iterator: " <<endl;

    for(it1=s.rbegin(); it1!=s.rend(); it1++)
        cout << *it1;
        cout <<endl;

    string str1= "Aditya Bharti" ;
    string str2= "Himanshu Bharti";

    char arr[50];

    str1.copy(arr,8, 0);
    arr[8]= '\0';

    cout << "character array after copying: " << arr <<endl << "\n\n";

    swap(str1, str2);

    cout << " String 1: " << str1  << "String 2: " << str2 <<endl << "\n\n";

*/
    string str3("Hi there! How are you?");

    string str4(str3);

    string str5(6, '^');

    string str6(str3, 4, 11);

    cout << "string 3: "<<str3 <<endl;
    cout <<"string 4: " <<str4 << endl;
    cout <<"string 5: " <<str5 << endl;
    cout <<"string 6: "<< str6 <<endl;

    str5.clear();

    string str7= str6;

    if(str3.find(str6) != string:: npos)
        cout << "string 6  is present in string 3 at: " << str3.find(str6) << endl;
    else
        cout << "string 6 is not present in string 3" << endl;


    cout << "string 7: " << str7 <<endl;

    cout << "length of str5 after clearing it : " <<str5.length() << endl;

    cout<< "String 7: " << str7 << endl;

    cout << "character at 2nd index in string 7 : " << str7.at(2) << endl;

    char ch= str7.back();

    cout << "front character of string 7: "<< str7.front() << endl << "end character of string 7: " << ch << endl;

    str6.append("something");

    str7.append(str6, 7, 10);

    cout << "string 6: " <<str6 <<endl;
    cout << "string 7: " <<str7 << endl;

    cout << str7.substr(3, 12) << endl;

    str6.replace(2,8, "Man of steel");

    cout << str6 << endl;


return 0;

}
