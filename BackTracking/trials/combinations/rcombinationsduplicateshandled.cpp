/* 

 Pascal’s Identity, i.e. ncr = n-1Cr + n-1Cr-1

 This algo is based on pascal's identity. For each element in the set we have 2 options either
 include the element at the current set_idx in the combination at comb_idx or do not include the
 element i.e ignore the element at current index.

 */



#include<bits/stdc++.h>

using namespace std;

void r_combinations(vector<int> &S, int r);
void r_combinations_helper(vector<int> &S, vector<int> &curr, int r, int comb_idx, int set_idx);
void print_vector(vector<int> &S);

int main(int argc, char const *argv[])
{
    /* code */
    vector<int> S{1, 2, 1, 3, 1,4,5};
;

    sort(S.begin(),S.end());
    
    r_combinations(S,3);

    return 0;
}

void r_combinations(vector<int> &S, int r){
    vector<int> curr_comb(r,0);
    r_combinations_helper(S,curr_comb, r,0,0);
}

void r_combinations_helper(vector<int> &S ,vector<int> &curr_comb, int r, int comb_idx,  int set_idx){
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
        //explore with the element chosen
        r_combinations_helper(S,curr_comb,r,comb_idx+1,set_idx+1);
        
        while(S[set_idx]==S[set_idx+1]){
            set_idx++;
        }

        //ignore the element at current set_idx and explore 
        //note: We have not incremented comb_idx here
        r_combinations_helper(S,curr_comb,r,comb_idx,set_idx+1);
    }
}



void print_vector(vector<int> &S){
    for(auto x:S){
        cout<<x;
    }
    cout<<endl;
}
