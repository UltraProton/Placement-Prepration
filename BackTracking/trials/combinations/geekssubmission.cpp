/* 

 Pascal’s Identity, i.e. ncr = n-1Cr + n-1Cr-1

 This algo is based on pascal's identity. For each element in the set we have 2 options either
 include the element at the current set_idx in the combination at comb_idx or do not include the
 element i.e ignore the element at current index.

 */



#include<bits/stdc++.h>

using namespace std;

void combination_sum(vector<int> &S, int target_sum);
void combination_sum_helper(vector<int> &S, vector<int> &curr, int target_sum, int set_idx);
void print_vector(vector<int> &S);


bool has_solution=false;


int main(int argc, char const *argv[])
{
    int t=0,n=0,x=0,target=0;
    cin>>t;

    while(t>0){
        cin>>n;
        vector<int> V;
        has_solution=false;
        
        while(n>0){
            cin>>x;
            V.emplace_back(x);
            n--;
        }
        
        cin>>target;

        //sort the input
        sort(V.begin(), V.end());
        
        //remove the duplicates from the set
        V.erase(unique(V.begin(),V.end()),V.end());

        combination_sum(V,target);

        if(!has_solution){
            cout<<"Empty";
        }
        
        cout<<endl;
        t--;
    }
    

    //print_grid(Grid);

    return 0;
}

void combination_sum(vector<int> &S, int target_sum){
    vector<int> curr_comb;
    combination_sum_helper(S,curr_comb, target_sum,0);
}

void combination_sum_helper(vector<int> &S ,vector<int> &curr_comb, int target_sum, int set_idx){
    //cout<<'x'<<endl;
    if(target_sum==0){
        has_solution=true;
        cout<<"(";
        print_vector(curr_comb);
        cout<<")";
        return;
    }

    else{
        for(int i=set_idx;i<S.size();i++){

            //if the element is bigger than the target sum then we can't include it in the set 
            if(S[i]>target_sum){
                break;
            }

            //choose...include the element in the combination
            curr_comb.emplace_back(S[i]);
            //explore with the element chosen
            //****Note: We have given i again because the element can again be included
            combination_sum_helper(S,curr_comb,target_sum-S[i],i);
            //the element included couldn't lear to a solution so...backtrack
            curr_comb.pop_back();    
        }
    }
}



void print_vector(vector<int> &S){
    int i=0;
    for(;i<S.size()-1;i++){
        cout<<S[i]<<" ";
    }
    cout<<S[i];
}
