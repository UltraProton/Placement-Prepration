#include<bits/stdc++.h>

using namespace std;

void permute(string &str);
void permute_helper(string &str, int l, int r);
void tab(int n);

int main(){
    string str="abc";
    permute(str);

    return 0;
}

void permute(string &str){
    string chosen="";
    permute_helper(str, 0, str.size()-1);
}

void permute_helper(string &str, int l, int r){
    tab(l);
    cout<<"fun( "<<str<<" l= "<<l<<" r= "<<r<<")"<<endl;
    if(l==r){
        cout<<str<<endl;
    }

    for(int i=l; i<=r; i++){
        swap(str[i],str[l]);
        permute_helper(str, l+1, r);
        swap(str[i], str[l]);
    }
}


void tab(int n){
    for(int i=1;i<=n;i++){
        cout<<"    ";
    }
}