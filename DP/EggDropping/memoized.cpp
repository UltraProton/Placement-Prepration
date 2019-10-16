#include<bits/stdc++.h>

using namespace std;

int egg_drop(int e, int floors,vector<vector<int>> &memo);

int main(int argc, char const *argv[])
{
    /* code */
    int e=0;
    int floors=0;
    int t=0;
    vector<vector<int>> memo;

    cin>>t;

    while(t>0){
        cin>>e>>floors;
        memo= vector<vector<int>>(e+5,vector<int>(floors+5,-1));
        cout<<egg_drop(e,floors,memo)<<endl;
        t--;
    }

    // char c='y';
    // while(c=='y'){
    //     cin>>e;
    //     cin>>floors;
    //     cout<<"ans: "<< egg_drop(e,floors)<<endl;
    //     cout<<"enter: character : ";
    //     cin>>c;
    // }
    // 
    return 0;
}

int egg_drop(int e, int floors, vector<vector<int>> &memo){
    if(memo[e][floors]!=-1){
        return memo[e][floors];
    }
    //* If the no of floors are 0 then we should not run the test and we require 0 tries
    //* If the no of floors are 1 then irrespective of the no of eggs we have we need only 1 try
    //* If the no of eggs are 1 then we are forced to try all the floors
    if(floors==0 || floors==1 || e==1){
        memo[e][floors]=floors;
        return floors;
    }

    //* Try all the possible floors starting from 1 till floors
    int ans= INT_MAX;
    for(int h=1;h<=floors;h++){
        //* Make a try and find the minimum of the following: 
        //* Either the egg breaks at floor h in which case we should find the ans in the floors below h (h-1,h-2,....2,1) with 
        //* one less egg or if the egg doesn't break then the ans lies in the floors above h (h+1,h+2....floors-1, floors) with the
        //* no of eggs still what we had  
        ans= min(ans, 1+ max(egg_drop(e-1,h-1,memo), egg_drop(e, floors-h,memo)));
        memo[e][floors]=ans;
    }

    return memo[e][floors];
}
