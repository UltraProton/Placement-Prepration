#include<bits/stdc++.h>
using namespace std;

int main(){
    int t=0;
    int a=0,b=0;
    cin>>t;
    while(t>0){
        cin>>a>>b;
        if(a%b==0){
            cout<<0<<endl;
        }
        else {
            cout<<(b-a%b)<<endl;
        }
        t--;
    }

    return 0;
}