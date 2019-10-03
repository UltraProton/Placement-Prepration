/* 
https://practice.geeksforgeeks.org/problems/longest-increasing-subsequence/0


 */



#include<bits/stdc++.h>

using namespace std;

int longest_inc_subseq(vector<int> &A);

int main(int argc, char const *argv[])
{
    vector<int> V;
    int n=0;
    int x=0;
    int t=0;

    cin>>t;

    while(t>0){
        V.clear();
        cin>>n;
        while(n>0){
            cin>>x;
            V.emplace_back(x);
            n--;
        }

        cout<<longest_inc_subseq(V)<<endl;
        
        t--;
    }

    return 0;
}

int longest_inc_subseq(vector<int> &A){
    int i=0;
    int j=0;
    int curr_max=0;
    int len=0;
    int ans=1;

    vector<int> table(A.size(),1);

    for(int i=1;i<A.size();i++){
        for(int j=0;j<i;j++){
            // if the ith element is bigger than the jth element which is to the left of i and including jth element in 
            // the increasing subsequence ending at i will increase the length of increasing subsequence ending at i then
            // include jth element in the increasing subsequence ending at i
            if(A[i]> A[j] && table[i] < table[j]+1){
                table[i]=table[j]+1;
                ans= max(ans,table[i]);
            }
        }
    }

    return ans;
}
