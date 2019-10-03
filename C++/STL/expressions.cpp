#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Expressions{
    string infix;
    string postfix;
    string prefix;

    stack <char> st;

    int associativity(int symbol){
        if(symbol == '^')
            return 'r';
        else
            return 'l';
    }

    int precedence(int op){
        if(op== '+' || op == '-')
            return 1;
        
        else if (op=='*' || op== '/')
            return 2;
        
        else if(op== '^')
            return 3;
        else
            return -1;
    }

    //constructor 
    

    public:
        Expressions(string );
        void infixtopostfix();
        void infixtoprefix();
        void postfixtoinfix();
        void prefixtoinfix();
        void prefixtopostfix();
        void postfixtoprefix();
};

Expressions :: Expressions(string infix){
    this->infix= infix;
    st.push('N');
    //cout << infix;
}

void Expressions :: infixtopostfix(){
    int len= infix.length();

    for(int i=0; i < len; i++){
        char current= infix.at(i);

        //cout << current << endl ;
    
        //if the current symbol is an operand simply push it to the postfix expression
        if(('a' <= current && current <= 'z') || ('A' <= current  && current <= 'Z') || ('0' <= current && current <= '9')){
            postfix.push_back(current);
           // cout << "postfix: " << postfix << endl;
        }
            
        // if the current symbol is a left parenthesis push it onto the stack
        else if(current== '(')
            st.push(current);
        
        else if(current== ')'){
            while(st.top() != '('){
                postfix.push_back(st.top());
                
                //if stack gets empty without finding a left parenthesis then expression is invalid 
                if(st.top()=='N'){
                    cout << "invalid expression" <<endl;
                    return;
                }
                
                else
                    st.pop();
            }

            // pop the left parenthesis
            if(st.top()=='N'){
                    cout << "invalid expression" <<endl;
                    return;
                }
            else
                st.pop();
        }

        else{
            int top_precedence= precedence(st.top());
            int current_precedence= precedence(current);
            int top_assoc= associativity(st.top());
            int curr_assoc=  associativity(current);
            
            while((top_precedence > current_precedence ) || (top_precedence == current_precedence && (top_assoc == 'l') && (st.top()!='('))){
                postfix.push_back(st.top());
                
                if(st.top()== 'N'){
                    cout << "error";
                    return;
                }

                st.pop();
                top_precedence= precedence(st.top());
                top_assoc= associativity(st.top());
            }

            st.push(current);
        }

    }

    // if there are symbols left in the stack then push them to the postfix expression

    while(st.top()!='N'){
        
        if(st.top()=='(' || st.top()==')'){
            cout << "Invalid expression entered" << endl ;

            return ;
        }

        postfix.push_back(st.top());
        st.pop();
    }

    cout << "Postfix expression: " << postfix << endl;

}


int main(int argc, char const *argv[])
{
    string infix= "3+4*2/(1-5)^2^3";


    Expressions expr(infix);

    expr.infixtopostfix();


    return 0;
}
