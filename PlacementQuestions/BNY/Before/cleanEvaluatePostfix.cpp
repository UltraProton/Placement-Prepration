#include<bits/stdc++.h>

using namespace std;


int evalRPN(vector<string>& tokens);

bool isoperator(char c);

int main(int argc, char const *argv[])
{
    /* code */
    vector<string> tokens{"10","6","9","3","+","-11","*","/","*","17","+","5","+"};

    cout<<evalRPN(tokens)<<endl;

    return 0;
}

bool isoperator(char c){
    return (c=='+' || c=='-' || c=='/' || c=='*');
}

int evaluate(int x, int y, int op){
    switch (op)
    {
    case '+' :  return x+y;  
        break;

    case '-': return x-y;
        break;

    case '*': return x*y;
        break;
    
    case '/': return x/y;
        break;

    default:
        break;
    }

    return -1;
}

int evalRPN(vector<string>& tokens) {
    int result=-1;
    stack<int> st;
    int a=0;
    int b=0;
    int c=0;
    for(auto x: tokens){
        if(x.size()> 1 || isdigit(x[0])){
            st.push(stoi(x));
        }
        else{
            b= st.top();
            st.pop();
            a=st.top();
            st.pop();
            c= evaluate(a,b,x[0]);
            st.push(c);
        }
        
        cout<<st.top()<<endl;
    }
    //cout<<st.top()<<endl;
    return st.top();
}