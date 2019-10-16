/* 

https://www.youtube.com/watch?v=vBdo7wtwlXs

https://www.geeksforgeeks.org/minimum-number-jumps-reach-endset-2on-solution/ : Good Explanation.

 */


#include<bits/stdc++.h>

using namespace std;

int min_jumps(vector<int> &V);

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
        cout<<min_jumps(V)<<endl;

        t--;
    }
    
    return 0;
}





int min_jumps(vector<int> &V){
    int n=V.size();
    if(n<1){
        return -1;
    }
    if(n==1){
        return 0;
    }

    int ladder_left=V[0]; 
    int max_ladder=V[0]; //* Stores the max possible index reachable in the input
    int n_jumps=1;

    for(int i=1;i<n;i++){
        if(i==n-1){ //* We have reached the end of the array so we have our answer so return jumps we have till now
            return n_jumps;
        }

        if(V[i] +i > max_ladder){ //* Build up the ladder
            max_ladder=V[i] + i;
        }

        ladder_left--; //* We have utilized stair on the ladder 

        if(ladder_left==0){ //* If the ladder left is zero 
            n_jumps++; //* We need to jump again i.e we have used all the stairs in the previous jump

            /* 
            If no more steps are remaining (i.e. steps=0, then we must have used a jump.Therefore increase jump. Since we
            know that it is possible somehow to reach maxladder, 
            ! we again initialize the steps to the number of steps to reach maxladder from position i.
            But before re-initializing step, we also check whether a step is becoming zero or negative.
            In this case, It is not possible to reach further. 
            
            */ 
            
            if(i>=max_ladder){  
                return -1;
            }

            ladder_left=max_ladder-i;
        }

    }

    return n_jumps;
}