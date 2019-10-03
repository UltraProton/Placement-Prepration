#include<bits/stdc++.h>

using namespace std;

void subset(vector<int> &S);
void subset_helper(vector<int> &S, vector<int> &curr, int curr_idx);
void print_vector(vector<int> &S);

int main(){
    vector<int> S{1,2,3};

    subset(S);

    return 0;
}


void subset_helper(vector<int> &S, vector<int> &curr, int curr_idx){
    cout<<"fun( curr_idx= "<<curr_idx<<endl;
    
    print_vector(curr);
    //for each element in the set S
    for(int i=curr_idx;i<S.size();i++){
        //choose the curr element
        curr.emplace_back(S[i]);
        //explore with the current element chosen
        subset_helper(S,curr,i+1);
        //unchoose
        curr.pop_back();
    }
}

void subset(vector<int> &S){
    vector<int> curr;
    subset_helper(S,curr,0);

}

void print_vector(vector<int> &S){
    for(auto x:S){
        cout<<x;
    }
    cout<<endl;
}
