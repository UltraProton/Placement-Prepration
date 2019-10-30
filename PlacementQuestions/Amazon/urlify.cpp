#include<bits/stdc++.h>
using namespace std;

char *urlify(string &str, int n);

int main(int argc, char const *argv[])
{
    /* code */
    string str=" ";
    int t=0;
    int n=0;
    cin>>t;
    while(t>0){        
        str.clear();
        cin.ignore();//! New thing learnt don't mix up the two formats of taking input even if you want to use both then before using 
        //! getline() use cin.ignore() which will flush the cin
        
        getline(cin,str);
        //cin>>str;
        cin>>n;
        char *ans= urlify(str,str.size());
        string temp="";
        for(int i=0;ans[i]!='\0';i++){
            temp+=ans[i];
        }

        cout<<temp<<endl;
        t--;
    }
    return 0;
}

char *urlify(string &str, int n){
    int i=0;
    while(str[i]==' '){
        i++;
    }

    str.erase(0,i);

    i=str.size()-1;
    while(str[i]==' '){
        i--;
    }

    str.erase(i+1,str.size());

    string temp="";
    
    for(auto x: str){
        if(x==' '){
            temp+="%20";
        }
        else{
            temp+=x;
        }
    }

    //cout<<temp<<endl;
    
    char *ans= new char[temp.size()+1];

    strcpy(ans,temp.c_str());//! One more new thing i.e copy the contents of string to char array but remember the size of the char array
    //!must be appropriate

    for(int i=0;i<temp.size();i++){
        ans[i]= temp[i];
    }


    // string x="";
    // for(int i=0;ans[i]!='\0';i++){
    //     x+=ans[i];
    // }

    // cout<<x<<endl;

    return ans;
}