#include<bits/stdc++.h>

using namespace std;

string pre_to_post(string &pre);
bool isop(int ch);
int main(int argc, char const *argv[])
{
    string pre="";
    int t=0;
    cin>>t;

    while (t>0)
    {   
        pre.clear();
        cin>>pre;
        cout<<pre_to_post(pre)<<endl;
        t--;
    }
    
    return 0;
}


string pre_to_post(string &pre){
    int n=pre.size();
    string ans="";
    stack<string> st;
    string a;
    string b;
    for(int i=n-1;i>=0;i--){
        if(isop(pre[i])){
            a=st.top();
            st.pop();
            b=st.top();
            st.pop();
            //! Here we need to create a new string and push that into the stack
            string temp= a+b+pre[i];
            st.push(temp);
        }
        else{
            //The string class has a constructor which allows to create a string object of the specified size and the character to be 
            //filled in the string object
            st.push(string(1,pre[i]));
        }
    }

    //! The final ans will be on top of stack
    return st.top();
}

bool isop(int ch){
    if(ch=='+' || ch=='-' || ch=='*' || ch=='/'){
        return true;
    }
    else{
        return false;
    }
}