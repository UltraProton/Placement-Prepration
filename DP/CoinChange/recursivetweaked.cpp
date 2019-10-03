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



        cin>>target;

        cout<<coin_change(S,S.size()-1,target)<<endl;

        S.clear();

        t--;
    }

    return 0;
}


int coin_change(vector<int> &S,int set_idx, int target){
    if(target<0){
        return 0;
    }
    /* Remember this condition always as to when we return 1 */
    //If the target is 0 then the only solution is to not choose any element in the change
    //* Relate these problems to subset sum problem which has a similar kind of case where if the target sum is 0 then we have 
    //* empty set as the only solution hence 1
    if(target==0){
        return 1;
    }

    // TWEAK: we return 0 only when set_idx < 0
    if(set_idx<0 && target>0){
        return 0;
    }

 
    else {
        //there are 2 ways
        return      coin_change(S,set_idx-1,target) //ignore the element to be included in the change 
                             + 
                    coin_change(S,set_idx,target-S[set_idx]); //include the element in the change
 
    } 
}
 

