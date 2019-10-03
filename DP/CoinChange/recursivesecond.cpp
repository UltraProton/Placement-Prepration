/* Here we don't need to sort the input. The logic is little bit different here.


Given a value N, if we want to make change for N cents, and we have infinite supply of each of S = { S1, S2, .. , Sm} valued
coins, how many ways can we make the change? The order of coins doesn’t matter.

For example, for N = 4 and S = {1,2,3}, there are four solutions: {1,1,1,1},{1,1,2},{2,2},{1,3}. So output should be 4. 
For N = 10 and S = {2, 5, 3, 6}, there are five solutions: {2,2,2,2,2}, {2,2,3,3}, {2,2,6}, {2,3,5} and {5,5}.

So the output should be 5.
 */

#include<bits/stdc++.h>

using namespace std;

int coin_change(vector<int> &S,int n, int target);

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

        cout<<coin_change(S,S.size(),target)<<endl;

        S.clear();

        t--;
    }

    return 0;
}


int coin_change(vector<int> &S,int n, int target){
    if(target<0){
        return 0;
    }
    //If the target is 0 then the only solution is to not choose any element in the change
    if(target==0){
        return 1;
    }

    //if target is still positive and we dont have any element left then no solution is possible
    if(n<=0 && target>0){
        return 0;
    }

 
    else {
        //there are 2 ways
        return      coin_change(S,n-1,target) //ignore the nth element to be included in the change 
                             + 
                    coin_change(S,n,target-S[n-1]); //include the nth element in the change and see if the same element
                                                    // can be further included in the set
                                                    // * Note that n is not decreased by one because we may include the 
                                                    // *element at n-1 index in the input array again
 
    } 
}
 

