
string infix_to_postfix(string &in);

int main(int argc, char const *argv[])
{
    /* code */
    string in="";
    int t=0;
    
    cin>>t;
    
    while (t>0)
    {   in.clear();
        cin>>in;
        //cout<<endl;
        cout<<infix_to_postfix(in)<<endl;
        t--;    
    }
    
    return 0;
}


string infix_to_postfix(string &in){
    string ans="";
    vector<int> prec(256,-1);
    stack<int> st;

    prec['^']=5;
    prec['*']=4;
    prec['/']=4;
    prec['+']=3;
    prec['-']=3;

    for(auto x: in){
        if(x>='a' && x<='z'){
            ans+=x;
        }
        //It is an operator
        else{
            //If the stack is empty or the current element is open parenthesis or the precedence of the element on top of stack is lower
            //than the precedence of current operator we can simply push x
            if(st.empty() || x=='(' || prec[st.top()]< prec[x]){
                st.push(x);
            }

            //If the current symbol is an opening parenthesis then we should keep popping the element from top of stack until we find a
            //closing parenthesis and then discard opening as well as closing parenthesis
            else if(x==')'){
                while(!st.empty() && st.top()!='('){
                    ans+=st.top();
                    st.pop();
                }

                if(st.top()=='('){
                    st.pop();
                }
            }

            else{
                
                while (!st.empty() && prec[st.top()]>=prec[x])
                {
                    ans+=st.top();
                    st.pop();
                }

                st.push(x);
            }
        }    
    }

    while(!st.empty()){
        ans+=st.top();
        st.pop();
    }

    return ans;
}