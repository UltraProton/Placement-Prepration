/* 

https://practice.geeksforgeeks.org/problems/cutting-binary-string/0/?track=sp-dynamic-programming&batchId=152

 */


#include<bits/stdc++.h>

using namespace std;

bool is_power(int x, int y);
int convert_binary(string &s);
bool is_power_5(string &s);
int cut_string(string &s);

int main(int argc, char const *argv[])
{
    int t=0;
    string str;
    
    cin>>t;
    while (t>0)
    {
        cin>>str;
        cout<<cut_string(str)<<endl;

        t--;
    }
    
    return 0;
}

/* 

1:     101
5:     101
125:   1111101
........

If you see the pattern of power of 5 then you realise that for a binary string to be power of 5 it should start with a 1 and
it shoudl end with a 1. These things are important in the logic below.

 */


int cut_string(string &s){

    int a= convert_binary(s);

    //* If the string is 0 then it can't be a power of 5 its a special case
    if(a==0){
        return -1;
    }

    int n=s.size();
    vector<int> table(n+1,10000);

    table[0]=0; //* length 0 string can't be cut    
    string x;

    //* for each string ending at length i
    for(int i=1;i<=n;i++){
        if(s[i-1]=='0'){ //* If there is a zero at i-1 then string from any j to i-1 can't be a power of 5
            continue;
        }

        //* check if the substring from j to i
        for(int j=0;j<i;j++){
            //* If there is any leading zero in the string from j to i then it can't be a power of 5
            if(s[j]=='0'){
                continue;
            }

            x= s.substr(j,i-j);
            
            //* if it is power of 5 
            if(is_power_5(x)){
                //* Check if the no of cuts for string length i are greater than no of cuts for string ending at j + 1(because
                //* we got a cut from j to i) 
                if(table[i] > table[j]+ 1){
                    table[i] =table[j]+1;
                }
            }
        }
    }

    // for(auto x:table){
    //     cout<<x<<" ";
    // }
    // cout<<endl;

    //* Check if the value at n is meaningful value 
    return table[n] < 100000 ? table[n]: -1;
}


//* check if x is a power of y or not
bool is_power(int x, int y){
    double val1=log(x)/log(y);
    int val2= val1;

    if(val1-val2<0.00000001){
        return true;
    }
    else{
        return false;
    }
}

int convert_binary(string &s){
    int ans=0;
    for(int i=0;i<s.size();i++){
        ans= 2*ans+ (s[i]-'0');
    }

    return ans;
}

bool is_power_5(string &s){
    int x= convert_binary(s);
    if(is_power(x,5)){
        return true;
    }
    else{
        return false;
    }
}