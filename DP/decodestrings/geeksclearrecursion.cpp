/* 

* Basically we need to get rid of the map.

 */

#include<bits/stdc++.h>

using namespace std;

int decode_count(string &str, int n);

int main(int argc, char const *argv[])
{
    /* code */
    int t=0,n=0;
    string str;

    cin>>t;
    while(t>0){
        str.clear();
        cin>>n;
        cin>>str;
        cout<<decode_count(str,n);
        t--;
    }
    return 0;
}

int decode_count(string &str, int n){
    //* If the string is empty or it is of length 1 and the only character in the string is not '0' then we have a decoding
    if(n==0 || n==1 && str[0]!='0'){
        return 1;
    }

    int ans=0;

    // leading zeros are not allowed
    //* We don't need this condition as it is handled because if the test passes above case say in case of "01" then the only case
    //* of recursion which will be the executed will be the first one. And the result of which will be 0 so the overall ans will 
    //* be 0
    if(str[0]=='0'){
        return 0; 
    }

    //* If the last digit is not 0 then last digit will be a part of decoding
    if(str[n-1] > '0'){
        ans+=decode_count(str,n-1);
    }


    //* If the last 2 digits in the string from a no less than 26 then it is a valid no and it should be included in the ans
    //* i.e it will be a part of decoding
    //* If the first character in length 2 string is 1 then no matter what follows it will be less than 26 and if the first character
    //* is 2 then the second character must be less than 7 for the string to be part of decoding
    if(str[n-2] == '1' || str[n-2]=='2' && str[n-1] < '7'){
        ans += decode_count(str,n-2); 
    }

    return ans;

}
