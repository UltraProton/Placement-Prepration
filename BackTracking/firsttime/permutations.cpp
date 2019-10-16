#include<bits/stdc++.h>

using namespace std;
void permuteStanford(string &str,string chosen);
void permuteBest(string str,int l,int r);
void permuteMy(string &str, int idx, string chosen);
void tab(int n);

int main(){
    string str="abc";
    //permuteStanford(str,"");
    //permuteMy(str,0,"");
    permuteBest(str,0,str.size()-1);

    return 0;
}

void permuteStanford(string &str, string chosen){
    tab(chosen.size());
    cout<<"fun(str= "<<str<<" chosen= "<<chosen<<")";
    cout<<endl;  
    if(str.empty()){
        cout<<chosen<<endl;
    }
    else{
        //for each character str[i] in the input string
        for(int i=0;i<str.size();i++){
            char c=str[i];
            //choose c to be the first character
            chosen.push_back(c);
            //remove this character from the input string
            str.erase(i,1);
            //recurse for the remaining string with c as the first character of chosen
            permuteStanford(str,chosen);
            //remove the chosen character triggering backtracking
            chosen.erase(chosen.size()-1,1);
            //insert back the removed character from the string
            str.insert(i,1,c);
        }
    }
}

/* This algorithm doesn't work

void permuteMy(string &str, int idx,string chosen){
    tab(chosen.size());
    cout<<"fun(str= "<<str<<" chosen= "<<chosen<<" idx="<<idx<<")";
    cout<<endl;

    if(chosen.size()==str.size()){
        cout<<chosen<<endl;
    }
    else{
        for(int i=idx;i<str.size();i++){
            chosen.push_back(str[i]);
            permuteMy(str,i+1,chosen);
            chosen.pop_back();
        }
    }

}

 */

void permuteBest(string str, int l, int r){
    tab(l);
    cout<<"fun(str= "<<str<<" l= "<<l<<" r= "<<r<<")";
    cout<<endl; 
    
    if(l==r){
        cout<<str<<endl;
    }
    else{
        for(int i=l;i<=r;i++){
            
            swap(str[l],str[i]);
            permuteBest(str,l+1,r);  
            swap(str[l],str[i]);
        }        
    }
}

void tab(int n){
    for(int i=1;i<=n;i++){
        cout<<"    ";
    }
}