#include<bits/stdc++.h>
#include<iostream>

using namespace std;

int hammingDistance(int a, int b){
    int ans=0;
    for(unsigned int x=a^b;x>0;x>>=1){
        if(x&1)
            ++ans; 
    }
    return ans;
}

int main(void){
    cout<<hammingDistance(0,3)<<endl;
    return 0;
}