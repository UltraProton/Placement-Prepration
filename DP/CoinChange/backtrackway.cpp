/* https://www.youtube.com/watch?v=irFtGMLbf-s   */ 

/* Sorting is very important in this problem. */

#include<bits/stdc++.h>

using namespace std;

void combination_sum(vector<int> &S, int target_sum, int &n_change);
void combination_sum_helper(vector<int> &S, vector<int> &curr, int target_sum, int set_idx, int &nchange);
void print_vector(vector<int> &S);

int main(int argc, char const *argv[])
{
    /* code */
    int t=0;
    int m=0;
    vector<int> S;
    int x=0;
    int target=0;
    int n_change=0;
    cin>>t;

    while(t>0)
    {   
        n_change=0;
        cin>>m;
        while(m>0){
            cin>>x;
            S.emplace_back(x);
            m--;
        }

        std::sort(S.begin(), S.end());

        cin>>target;

        combination_sum(S,target,n_change);

        cout<<n_change<<endl;

        S.clear();

        t--;
    }


    return 0;
}

void combination_sum(vector<int> &S, int target_sum,int &n_change){
    vector<int> curr_comb;
    combination_sum_helper(S,curr_comb, target_sum,0,n_change);
}

void combination_sum_helper(vector<int> &S ,vector<int> &curr_comb, int target_sum, int set_idx, int &n_change){
    if(target_sum==0){
        n_change++;
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
            combination_sum_helper(S,curr_comb,target_sum-S[i],i,n_change);
            //the element included couldn't lear to a solution so...backtrack
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
