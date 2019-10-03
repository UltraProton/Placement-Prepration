/* 

 Pascal’s Identity, i.e. ncr = n-1Cr + n-1Cr-1

 This algo is based on pascal's identity. For each element in the set we have 2 options either
 include the element at the current set_idx in the combination at comb_idx or do not include the
 element i.e ignore the element at current index.

 https://www.youtube.com/watch?v=irFtGMLbf-s   
 
 *********************************Sorting is very crucial here********************************** 
 
 */ 


#include<bits/stdc++.h>

using namespace std;

void combination_sum(vector<int> &S, int target_sum);
void combination_sum_helper(vector<int> &S, vector<int> &curr, int target_sum, int set_idx);
void print_vector(vector<int> &S);

int main(int argc, char const *argv[])
{
    /* code */
    vector<int> S{1,2,3,4,5};

    //crucial step
    std::sort(S.begin(), S.end());
    
    combination_sum(S,8);

    return 0;
}

void combination_sum(vector<int> &S, int target_sum){
    vector<int> curr_comb;
    combination_sum_helper(S,curr_comb, target_sum,0);
}

void combination_sum_helper(vector<int> &S ,vector<int> &curr_comb, int target_sum, int set_idx){
    if(target_sum==0){
        print_vector(curr_comb);
        return;
    }

    else{
        //consider each element in the set
        for(int i=set_idx;i<S.size();i++){

            //if the element is bigger than the target sum then we can't include it in the set 
            //if we include S[i] then target sum will become negative
            if(0>target_sum-S[i]){
                break;
            }

            //choose...include the element in the combination
            curr_comb.emplace_back(S[i]);
            //explore with the element chosen
            //****Note: We have given i again because the element can again be included
            combination_sum_helper(S,curr_comb,target_sum-S[i],i);
            //the element included couldn't lead to a solution so...backtrack
            curr_comb.pop_back();    
        }
    }
}

void print_vector(vector<int> &S){
    for(auto x:S){
        cout<<x;
    }
    cout<<endl;
}
