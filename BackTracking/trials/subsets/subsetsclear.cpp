#include<bits/stdc++.h>

using namespace std;

void subset(vector<int> &S);
void subset_helper(vector<int> &S, vector<int> &curr, int curr_idx);
void print_vector(vector<int> &S);

int main(int argc, char const *argv[])
{
    vector<int> S{1,2,3};
    subset(S);

    return 0;
}

void subset(vector<int> &S){
    vector<int> curr;
    subset_helper(S,curr, 0);
}

/* This doesn't handle duplicates in the set */
void subset_helper(vector<int> &S, vector<int> &curr, int curr_idx){
    //always remember this condition
    if(curr_idx==S.size()){
        print_vector(curr);
    }
    else{
        //include the element at curr index in the set
        curr.emplace_back(S[curr_idx]);
        //explore with the element at curr index included
        subset_helper(S,curr,curr_idx+1);
        //remove the included element
        curr.pop_back(); //backtrack
        //explore without the current element being included i.e after element is removed
        
        subset_helper(S,curr,curr_idx+1);
    }
}

void print_vector(vector<int> &S){
    for(auto x:S){
        cout<<x;
    }
    cout<<endl;
}


