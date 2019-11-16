#include<bits/stdc++.h>

using namespace std;

int fun(int m, int l);

int main(){
    int m=0,l=0;
    cin>>m>>l;
    cout<<fun(m,l)<<endl;
    return 0;
}

int fun(int m, int l){
    queue<int> q;
    q.push(2);
    q.push(-1);
    int ans=1;
    int x=0;
    
    vector<int> dp(m,0);
    //First precompute the values in a table for each m
    for(int i=0;i<m;i++){
        dp[i]=((i*i)+1)%m;
    }

    //For each level
    while(l>1){
        //Until we have processed this level
        while(q.front()!=-1){
            x=q.front();
            //Keep popping the values from the queue for this level
            q.pop();
            //Add the no of ships that can follow the current ship
            ans+=dp[x];
            //Push those ships in the next level of the current ship
            for(int i=0;i<dp[x];i++){
                q.push(i);
            }
        }
        //Remove the -1 after the level
        q.pop();
        //push -1 marker again in the queue
        q.push(-1);
        //decrement the level
        l--;
    }

    return ans%m;
}