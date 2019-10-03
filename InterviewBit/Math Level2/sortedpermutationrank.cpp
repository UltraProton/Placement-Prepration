#include<bits/stdc++.h>
#include<iostream>

using namespace std;
int update_count(int *count, char ch);
void incr_update_count(int *count, string str);
long long sortedpermrank(string str);
long long fact(int n){
    long long ans=1;
    for(int i=n;i>1;i--)
        ans*=i;
    return ans;
}

int main(void){
    string s="STRING";
    cout<<sortedpermrank(s);

    return 0;
}

int update_count(int *count, char ch){
    for(int i=ch;i<256;i++)
        count[i]--;
}

void incr_update_count(int *count, string str){
    for(int i=0;str[i];i++)
        count[str[i]]++;
    for(int i=1;i<256;i++)
         count[i]+=count[i-1];
}

long long sortedpermrank(string str){
    int count[256];
    memset(count,0,sizeof(count));
    long long ans=0;
    int len=str.size();
    long long f=fact(len);
    incr_update_count(count,str);

    for(int i=0;str[i];i++){
        f/=(len-i);
        ans+=f*count[str[i]-1];
        update_count(count,str[i]);
    }

    return (ans+1);
}