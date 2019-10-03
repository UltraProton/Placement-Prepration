/* 

https://leetcode.com/articles/jump-game/ : Very good detailed article

For each of the index in the input we mark it as bad index or good index if we are able to reach end from the index then it is a 
good index otherwise it is a bad index. So the question is whether 0 is a good index or bad index.

*/


#include<bits/stdc++.h>

using namespace std;

enum type{ good, bad, undefined};

bool jump_possible(vector<int> &arr);
bool jump_possible_helper(vector<int> &arr,int curr_idx, int n,vector<type> &memo);

int main(int argc, char const *argv[])
{
    /* code */
    vector<int> V;
    int t=0,n=0,x=0;
    cin>>t;

    while(t>0){
        V.clear();
        cin>>n;
        while(n>0){
            cin>>x;
            V.emplace_back(x);
            n--;
        }

        // for(auto ele: V){
        //     cout<<ele<<" ";
        // }
        int ans=INT_MAX;
        cout<<jump_possible(V)<<endl;

        t--;
    }
    return 0;
}

bool jump_possible(vector<int> &A){
    vector<type> memo(A.size(),undefined);
    return jump_possible_helper(A,0,A.size(), memo); //* Find whether 0 is a good index or bad index
}

bool jump_possible_helper(vector<int> &arr, int curr_idx, int n, vector<type> &memo){
    if(memo[curr_idx]!=undefined){
        if(memo[curr_idx]==good){
            return true;
        }
        else{
            return false;
        }
    }
    //* If the starting position is the end position then we are at the end position and we say its possible to reach end
    if(curr_idx==n-1){
        memo[curr_idx]=good;
        return true;
    }

    else{
        int max_reach=min(n-1,curr_idx+arr[curr_idx]); //* How far we can reach from the current index`
        //* for each possibility of jump from the current position + 1 in the array 
        for(int next_idx=curr_idx+1;next_idx<=max_reach ;next_idx++){
            //cout<<'x'<<endl;
            if(jump_possible_helper(arr,next_idx,n,memo)){//* If we can reach end from any of the next indexes
                memo[curr_idx]=good;
                return true;
            }
        }

        memo[curr_idx]=bad;
    
        return false;
    }
}