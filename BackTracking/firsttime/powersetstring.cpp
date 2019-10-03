

/*Implement the powerset of a set with duplicates allowed. [] */


#include<bits/stdc++.h>

using namespace std;

void powerset(string &str,int idx=-1,string chosen="");
void powersetDFS(string &str, int idx=0, string chosen="");
void tab(int n);

int main(){
    string str="abc";
    powersetDFS(str,0,"");
    return 0;
}


void powerset(string &str, int idx,string chosen){
    tab(chosen.size());
    cout<<"fun(index= "<<idx<<" chosen= "<<chosen<<")";
    cout<<endl;

    if(idx==str.size()){
        return;
    }

    for(int i=idx+1;i<str.size();i++){
        chosen+=str[i];
        powerset(str,i,chosen);
        chosen.erase(chosen.size()-1);
    }
}


void powersetDFS(string &str, int idx, string chosen){
    tab(chosen.size());
    cout<<"fun(index= "<<idx<<" chosen= "<<chosen<<")";
    cout<<endl;   
    //for each element in the set
    for(int i=idx;i<str.size();i++){
        //choose the element at the current index
        chosen+=str[i];
        //recurse for the elements after the current index
        powersetDFS(str,i+1,chosen);
        //remove the element triggers backtracking
        chosen.erase(chosen.size()-1);
    }

    return;

}


void tab(int n){
    for(int i=1;i<=n;i++){
        cout<<"    ";
    }
}