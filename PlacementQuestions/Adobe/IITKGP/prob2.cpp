#include<bits/stdc++.h>

using namespace std;

string max_occurences(string &str);

bool comp(const pair<string,int> &p1, const pair<string, int> &p2){
    return p1.second> p2.second;
}

int main(int argc, char const *argv[])
{
    /* code */
    string str="";
    cin>>str;
    
    max_occurences(str);

    return 0;
}

string max_occurences(string &str){
    map<string, int > mp;
    string temp="";
    int j=0;
    for(int i=0;i<=str.size()-5;i++){
        //cout<<str.substr(i,j)<<endl;
        temp= str.substr(i,5);
        //cout<<temp<<endl;
        mp[temp]+=1;
    }

    //auto itr= max_element(mp.begin(), mp.end(), [](const pair<string, int> &p1, const pair<string> &p2){p1.second>p2.second})

    //Remember max_element gives iterator pointing to the first element in the map
    //auto x= max_element(mp.begin(), mp.end(), comp);

    //cout<<endl;
    //cout<<x->first<<endl;
    int max_occur=INT_MIN;
    string ans="";
    for(auto it=mp.begin();it!=mp.end();it++){
        if(it->second> max_occur){
            max_occur= it->second;
            ans=it->first;
        }
        //cout<<it->first<<" "<<it->second<<endl;
    }

    cout<<ans<<endl;

    return " ";
}