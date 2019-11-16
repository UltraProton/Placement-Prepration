#include<bits/stdc++.h>
using namespace std;

int longest_valid_parens(string &str);
bool isvalid(int l,int r, string &str);

int main(){
    string str="";
    cin>>str;

    cout<<str<<endl;

    cout<<longest_valid_parens(str)<<endl;

    return 0;
}

int longest_valid_parens(string &str){
    int ans=INT_MIN;
    int n=str.size();

    //cout<<n<<endl;
    int i=0,j=0;
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            if(isvalid(i,j,str)){
                ans=max(ans,j-i+1);
            }
        }
    }

    return ans;
}

bool isvalid(int l, int r, string &str){
    stack<int> st;
    for(int i=l;i<=r;i++){
        if(str[i]=='('){
            st.push(str[i]);
            continue;
        }
        
        //If the stack is empty and we have a current element as closing parens then we have a mismatch
        if(st.empty()){
            return false;
        }
        
        else{
            int x=st.top();
            st.pop();
            if(x!='('){
                return false;
            }
        }
    }
    
    return (st.empty());
}