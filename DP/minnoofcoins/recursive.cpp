/* 

https://practice.geeksforgeeks.org/problems/number-of-coins/0

*/

#include<bits/stdc++.h>

using namespace std;

int min_coins(vector<int> &V,int target);

int main(int argc, char const *argv[])
{
    /* code */
    int t=0,v=0,n=0,x=0,y=0;
    vector<int> V;
    cin>>t;
    while(t>0){
        cin>>v;
        cin>>n;
        y=n;

        while(y>0){
            cin>>y;
            V.emplace_back(y);
            y--;
        }
        cout<<min_coins(V,v)<<endl;

        t--;
    }
    return 0;
}

int min_coins(vector<int> &V,int target){
    if(target <= 0){
        return 0;
    }    

    int ans=INT_MAX;
    int sub_res=0;

    for(int i=0;i<V.size();i++){   //* Try each possible coin in the input         
        if(target>=V[i]){//* If the coin value at the index i in the input is less than or equal to target then we can include the
                         //* coin at index i
            sub_res= min_coins(V,target-V[i]); //* Find the ans with the coin included i.e find the min no of coins if the target is V[i] 
                                              //* less find the no of coins needed in that case. After we have found that we will just
                                              //* add 1 coin for our case to get the final result 

            if(sub_res!=INT_MAX && sub_res+1 < ans){ //* If sub_res is INT_MAX then we don't want to check subres+1 which will cause integer overflow.
                                         //*  So basically we are avoiding the cases where the sub_res is INT_MAX which is not a possible ans.
                                         //* So the second check is whether the ans calculated from the subcall + 1(coin included in
                                         //* current call) is less than the ans. Remember we are keeping track of the min ans. If in 
                                         //* any other call we had a smaller ans then we won't change it. Otherwise we have got a new
                                         //* minimum ans so we should save it. 
                ans=sub_res+1;
            }
        }
    }

    return ans;
}
