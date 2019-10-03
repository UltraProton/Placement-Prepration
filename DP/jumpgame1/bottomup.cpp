#include<bits/stdc++.h>

using namespace std;

bool jump_possible(vector<int> &V);

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

bool jump_possible(vector<int> &V){
    int n=V.size();
    vector<int> table(n,0);

    table[n-1]=1; //* Last is reachable from last position

    int max_reach=0;
    //* For each index i to the left of last index are we able to reach i from the the last index
    //* Its the reverse process if we are able to reach from right to left then certainly we will be able to reach from left to right 
    for(int i=n-2;i>=0;i--){
        max_reach= min(i+V[i],n-1); //* From the ith index we can go to the right upto min(i+V[i], n-1)
        for(int j=i+1;j<=max_reach;j++){
            if(table[j]==1){
                table[i]=1;
                break;
            }
        }
    }

    return table[0]==1;//* If table[0] is 1 then we have found in going from right to left one way such that we can reach to
                       //* destination from 0 

}


