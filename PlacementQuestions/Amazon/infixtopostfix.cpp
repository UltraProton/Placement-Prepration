#include<bits/stdc++.h>

using namespace std;

char *intopost(string &in);

int main(int argc, char const *argv[])
{
    /* code */
    string in="";
    
    cin>>in;
    
    
    char *ans= intopost(in);

    cout<<'x'<<endl;
    
    string temp="";
    for(int i=0;ans[i]!='\0';i++){
        temp+=ans[i];
    }

    cout<<temp<<endl;

    return 0;
}

char *intopost(string &in){
    stack<int> st;
    string post="";
    vector<int> prec(256,-1);

    prec['^']=5;
    prec['*']=4;
    prec['/']=4;
    prec['+']=3;
    prec['-']=3;

    for(auto ch: in){
        //cout<<'x'<<endl;
        
        if(ch>='a' && ch<='z'){
            post+=char(st.top());
        }


        else{
            if(st.empty() || ch=='(' || prec[st.top()] < prec[ch]){
                st.push(ch);
            }
            else if(ch==')'){
                while(!st.empty() && st.top()!='('){
                    post+=char(st.top());
                    st.pop();
                }

                if(st.top()=='('){
                    st.pop();
                }
            }
            else{
                while(!st.empty() && prec[st.top()]>=prec[ch]){
                    post+=char(st.top());
                    st.pop();
                }
                st.push(ch);
            }
        }
    }

    while(!st.empty()){
        post+=char(st.top());
        st.pop();
    }

    cout<<post.empty()<<endl;
    cout<<in<<endl;
    cout<<post<<endl;
  
    char *ans= new char[post.size()+1];

    strcpy(ans, post.c_str());

    return ans;
}