/* 
https://practice.geeksforgeeks.org/problems/longest-increasing-subsequence/0

! This code is incorrect doesn't work on 2nd test case of the sample input of the above problem. 

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
    int ans=INT_MIN;
    for(int i=0;i<A.size()-1;i++){
        for(int j=i+1;j<A.size();j++){
            if(A[j]>A[i]){
                curr_max=A[j];
                len=2;
                for(int k=j;k<A.size();k++){
                    if(curr_max < A[k]){
                        len++;
                        curr_max=A[k];
                        ans= max(ans,len);
                    }
                }
            }
        }
    }

    return ans;
}
