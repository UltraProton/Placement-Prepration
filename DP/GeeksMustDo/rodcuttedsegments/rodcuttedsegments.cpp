/* 

https://practice.geeksforgeeks.org/problems/cutted-segments/0

 */

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int cutted_segments(int x, int y, int z , int n);

int main()
 {
    int n=0,t=0,i=0,x=0,y=0,z=0;
    cin>>t;
    while(t>0){
        cin>>n;
        cin>>x>>y>>z;   
        cout<<cutted_segments(x,y,z,n)<<endl;
        t--;
    }
	return 0;
}

int cutted_segments(int x, int y, int z, int n){
    vector<int> table(n+2,-1);
    table[0]=0;
    for(int i=0;i<=n;i++){
        //if the cut is not possible at 'i' then continue
        if(table[i]==-1){
            continue;
        }
    
        if(i+x<=n){
            table[i+x]= max(table[i]+1,table[i+x]);
        }

        if(i+y<=n){
            table[i+y]= max(table[i]+1,table[i+y]);
        }

        if(i+z<=n){
            table[i+z]= max(table[i]+1,table[i+z]);
        }
    }

    return table[n];
}
