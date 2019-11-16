#include<bits/stdc++.h>

using namespace std;

bool balancedparens(string &str);

int main(){
    string str="";
    cin>>str;
    cout<<balancedparens(str)<<endl;
}

bool balancedparens(string &str){
    stack<int> st;
    for(auto x:str){
        if(x=='(' || x=='['|| x=='{'){
            st.push(x);
            continue;
        }

        int t=0;

        //If we have got a closing parenthesis and the stack is empty then there is no opening paren for the current closing parens
        if(st.empty()){
            return false;
        }

        else{
            switch(x){
                case ')':t=st.top(); st.pop(); if(t!='(') return false;break;
                case ']':t=st.top(); st.pop(); if(t!='[') return false; break;
                case '}':t=st.top(); st.pop(); if(t!='{') return false;break;
            }
        }
    }

    return (st.empty());
}