/* 
https://www.hackerrank.com/contests/code-maestros-14-04/challenges/baby-step/submissions/code/1317224647 
 */

#include<bits/stdc++.h>

using namespace std;

void in_to_post(string &in);

int main(int argc, char const *argv[])
{
    /* code */
    string in;
    int n=0;
    cin>>n;
    while(n>0){        
        cin>>in;
        in_to_post(in);
        cout<<endl;
        n--;
    }
    return 0;
}

void in_to_post(string &in){
    vector<int> prec(256,-1);
    stack<int> st;
    prec['^']=10;
    prec['*']=5;
    prec['/']=5;
    prec['+']=3;
    prec['-']=3;

    
    for(auto ch : in){
        //If the current symbol is a character
        if(ch>='a' && ch<='z'){
            cout<<ch;
        }
        //If the current symbol is not an operand
        else{
            //If the stack is empty or the current symbol is '(' or the precedence of the current symbol is greater
            //than the precedence of the symbol on the top of stack then we can simply push the current character
            if(st.empty() || ch=='(' || prec[st.top()]< prec[ch]){
                st.push(ch);
            }
            //If the current symbol is ')'
            else if(ch==')'){
                //Until we find a closing parenthesis keep popping the characters and output
                while (!st.empty() && st.top()!='(')
                {
                    cout<<char(st.top());
                    st.pop();
                }

                //If the final symbol we find is a '(' then pop that as well
                if(st.top()=='('){
                    st.pop();
                }
            }
            else{
                //If the prec of the top of stack is greater than the current symbol then keep popping the 
                //characters from the stack until this condition is false
                while (!st.empty() && prec[st.top()] >=prec[ch])
                {
                    cout<<char(st.top());
                    st.pop();
                }
                //After all the operators with high precedence are removed from the stack push the current symbol
                //inside it
                st.push(ch);
            }
        }
    }

    //Pop out any remaining symbols from the stack
    while(!st.empty()){
        cout<<char(st.top());
        st.pop();
    }
}