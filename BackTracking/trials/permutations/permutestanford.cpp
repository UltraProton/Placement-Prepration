#include<bits/stdc++.h>

using namespace std;

void permute(string &str);
void permute_helper(string &str, string &chosen);
void tab(int n);

int main(){
    string str="abc";
    permute(str);

    return 0;
}

void permute(string &str){
    string chosen="";
    permute_helper(str,chosen);
}

void permute_helper(string &str, string &chosen){
    tab(chosen.size());
    cout<<"fun( str="<< str<<" chosen= "<<chosen<<" )"<<endl;
    if(str.size()==0){
        cout<<chosen<<endl;
    }
    else{
        for(int i=0;i<str.size();i++){
            char curr_char= str[i];
            chosen+=char(curr_char); //choose the character at the ith position to be chosen
            str.erase(i,1); // remove that character from the string so that the next choice is from remaining characters
            // explore
            permute_helper(str,chosen); 
            
            // insert the removed character back to the string
            str.insert(i,1,curr_char);  //https://stackoverflow.com/questions/3223302/c-insert-char-to-a-string
            
            //unchoose the chosen character
            chosen.pop_back(); 
        }
    }
}


void tab(int n){
    for(int i=1;i<=n;i++){
        cout<<"    ";
    }
}