/* Here the logic is same as combination sum but we just want no of those combinations not the list of those
combinations so we are not storing those combinations here. Our logic mainly there and here is same to return
and say we got the ans if the target sum becomes 0.

Very important: We need to sort the input for this logic.


 */

// ! check if it works or not 
// ? yes it works

#include<bits/stdc++.h>

using namespace std;

int coin_change(vector<int> &S,int set_idx, int target);

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

        cout<<coin_change(S,0,target)<<endl;

        S.clear();

        t--;
    }

    return 0;
}


int coin_change(vector<int> &S,int set_idx, int target){
    if(target==0){
        return 1;
    }
    else{
        int ans=0;
        for(int i=set_idx;i<S.size();i++){
            if(S[i]> target){
                break;
            }

            ans= ans + coin_change(S,i,target-S[i]);
        }

        return ans;
    }
}

