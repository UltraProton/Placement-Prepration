/* 

 Pascal’s Identity, i.e. ncr = n-1Cr + n-1Cr-1

 This algo is based on pascal's identity. For each element in the set we have 2 options either
 include the element at the current set_idx in the combination at comb_idx or do not include the
 element i.e ignore the element at set index.

 Remember if the elements are distinct then we don't need to sort the array to handle the duplicates.

 */



#include<bits/stdc++.h>

using namespace std;

void r_combinations(vector<int> &S, int r);
void r_combinations_helper(vector<int> &S, vector<int> &curr, int r, int comb_idx, int set_idx);
void print_vector(vector<int> &S);
void tab(int n);

int main(int argc, char const *argv[])
{
    /* code */
    vector<int> S{1,2,3,4,5};
    r_combinations(S,3);

    return 0;
}

void r_combinations(vector<int> &S, int r){
    vector<int> curr_comb(r,0);
    r_combinations_helper(S,curr_comb, r,0,0);
}

void r_combinations_helper(vector<int> &S ,vector<int> &curr_comb, int r, int comb_idx,  int set_idx){
    tab(curr_comb.size());
    cout<<"fun( comb_idx= "<<comb_idx<<"set_idx = "<<set_idx<<" )"<<endl;
    //we print the combination only when we have r elements present in it
    if(comb_idx==r){
        print_vector(curr_comb);
        //this return statement is important here
        return;
    }

    //this condition is also very important
    if(set_idx>=S.size()){
        return;
    }

    else{
        //choose...include the element at the current set index in the combination
        curr_comb[comb_idx]=S[set_idx];
        //explore with the element chosen to insert element at next comb_idx considering element at next set index 
        r_combinations_helper(S,curr_comb,r,comb_idx+1,set_idx+1);
        
        //ignore the element at current set_idx and explore 
        //note: We have not incremented comb_idx here...i.e we ignored the element at set_idx and want to explore element
        //at set_idx+1 to be inserted at comb_idx
        r_combinations_helper(S,curr_comb,r,comb_idx,set_idx+1);
    }
}

void print_vector(vector<int> &S){
    for(auto x:S){
        cout<<x;
    }
    cout<<endl;
}


void tab(int n){
    for(int i=1;i<=n;i++){
        cout<<"    ";
    }
}