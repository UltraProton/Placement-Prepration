#include<bits/stdc++.h>

using namespace std;

int coin_change(vector<int> &S,int set_idx, int target,vector<vector<int>> &memo);

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

    vector<vector<int>> memo;

    while(t>0)
    {   
        memo.clear();
        n_change=0;
        cin>>m;
        while(m>0){
            cin>>x;
            S.emplace_back(x);
            m--;
        }

        cin>>target;

        memo=  vector<vector<int>>(305,vector<int>(305,-1));
 
        cout<<coin_change(S,S.size()-1,target,memo)<<endl;

        S.clear();

        t--;
    }

    return 0;
}


int coin_change(vector<int> &S,int set_idx, int target,vector<vector<int>> &memo){
    if(target<0){
        return 0;
    }

    if(set_idx<0 && target>0){
        return 0;
    }
    
    
    if(memo[set_idx][target]!=-1){
        return memo[set_idx][target];
    }
  
    //If the target is 0 then the only solution is to not choose any element in the change
    if(target==0){
        memo[set_idx][target]=1;
        return 1;
    }

    else {
        //there are 2 ways
        memo[set_idx][target]= coin_change(S,set_idx-1,target,memo) //ignore the element to be included in the change 
                             + 
                        coin_change(S,set_idx,target-S[set_idx],memo); //include the element in the change

        return memo[set_idx][target];

    } 
}
 

