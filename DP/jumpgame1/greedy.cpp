/* 
https://leetcode.com/articles/jump-game/
 
 */

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
    int last_pos=n-1;

    //* For each index in going from right to left 
    for(int i=n-1;i>=0;i--){
        //* if we can reach the last good position from the current index then the current index itself if good position
        if(V[i]+ i >=last_pos){
            last_pos=i;
        }
    }

    //* If 0th index is the last good position then we will be able to reach the end
    return last_pos==0;
}
