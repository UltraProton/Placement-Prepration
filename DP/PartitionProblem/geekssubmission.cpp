#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

bool partition_possible(vector<int> &S);
bool subset_sum(vector<int> &S , int curr_idx, int target_sum,vector<vector<int>> &memo);
ll sum(vector<int> &S);

int main(int argc, char const *argv[])
{
    vector<int> S;
    int t=0,n=0,x=0;

    cin>>t;

    while(t>0){
        S.clear();
        cin>>n;
        while(n>0){
            cin>>x;
            S.emplace_back(x);
            n--;
        }

        if(partition_possible(S)){
            cout<<"YES";
        }
        else{
            cout<<"NO";
        }

        cout<<endl;

        t--;
    }
    

    return 0;
}

bool partition_possible(vector<int> &S){
    ll set_sum= sum(S);

    if(set_sum%2!=0){
        //cout<<'x'<<endl;
        return false;
    }

    vector<vector<int>> memo(205, vector<int>(set_sum/2+1,-1));

    return subset_sum(S,0,set_sum/2,memo);
}

bool subset_sum(vector<int> &S , int curr_idx, int target_sum,vector<vector<int>> &memo){
    if(target_sum<0){
        return false;
    }
    if(curr_idx>=S.size() && target_sum > 0){
        return false;
    }

    // * The below if condition should be after above two if's to avoid invalid index access 
    
    if(memo[curr_idx][target_sum]!=-1){
        return memo[curr_idx][target_sum];
    }


    if(target_sum==0){
        memo[curr_idx][target_sum]=1;
        return true;
    } 
    
    else{
        memo[curr_idx][target_sum]= (subset_sum(S,curr_idx+1,target_sum-S[curr_idx],memo) 
                                        || 
                                    subset_sum(S,curr_idx+1,target_sum,memo)); 
        
        return memo[curr_idx][target_sum]; 
    }
}


ll sum(vector<int> &S){
    int ans=0;
    for(auto x:S){
        ans+=x;
    }

    return ans;
}
