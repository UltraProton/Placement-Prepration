#include<bits/stdc++.h>

using namespace std;
vector<int> substr_concat(string &str, vector<string> &L);
vector<int> substr_concat_better(string &str, vector<string> &L);
void permute(vector<string> &L,unordered_map<string,int> &mp,int l_idx, int r_idx);

int main(){
    string str= "abcdababcd";
    
         
    //cout<<str.size()<<endl;
    vector<string> L{"ab", "ab", "cd"};
    
    vector<int> indexes= substr_concat(str,L);
   

    for(auto x:indexes){
        cout<<x<<" ";
    }   

    return 0;
}

vector<int> substr_concat(string &str,vector<string> &L){
    unordered_map<string,int>mp;
    //stores the permutations of elements in L
    int str_size=str.size();
    //vector<string> permutations_of_L;
    vector<int> indexes;

    permute(L,mp,0,L.size()-1);

    int n_words= L.size();
    int word_len=L[0].size();
    int substr_size= n_words*word_len;

/*  for(auto x:permutations_of_L){
        cout<<x<<endl;
    }
    int substr_size= permutations_of_L[0].size();
    
    for(auto x:permutations_of_L){
        mp[x]=1;
    }
   */    
    
  
    for(int i=0;i<(str_size-substr_size+1);i++){
        if(mp.find(str.substr(i,substr_size))!=mp.end()){
            indexes.push_back(i);
        }
        //cout<<i<<endl;
    }

    return indexes;

}

void permute(vector<string> &L, unordered_map<string,int> &mp, int l_idx, int r_idx){
    if(l_idx==r_idx){
        string temp;
        for(auto x:L){
            temp.append(x);
        }
        mp[temp]=1;
    }

    for(int i=l_idx;i<=r_idx;i++){
        swap(L[i],L[l_idx]);
        permute(L,mp,l_idx+1,r_idx);
        swap(L[i],L[l_idx]);
    }
}

