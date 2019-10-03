#include<bits/stdc++.h>

using namespace std;

int max_sum_inc_subseq(vector<int> &V);

int main(int argc, char const *argv[])
{
    /* code */
    int t=0;
    int n=0;
    int x=0;
    vector<int> V;
    cin>>t;
    while(t>0){
        V.clear();
        cin>>n;
        while(n>0){
            cin>>x;
            V.emplace_back(x);
            n--;
        }

        cout<<max_sum_inc_subseq(V)<<endl;
        t--;
    }
    return 0;
}

// int max_sum_inc_subseq(vector<int> &V){
//     int n=V.size();
//     vector<int> indices(10,0);
//     vector<int> table(20,1);

//     int max_len=0;
//     int idx=-1;

//     for(int i=1;i<n;i++){
//         for(int j=0;j<i;j++){
//             if(V[i] > V[j] && table[j]+1 > table[i] ){
//                 table[i]=table[j]+1;
//                 if(max_len < table[i]){
//                     idx=i;
//                 }
//                 max_len= max(max_len,table[i]);
//                 indices[i]= j;
                
//             }
//         }
//     }

//     int ans=0;

//     int i=idx;
//     ans+=V[idx];
//     while(i>0){
//         ans+= V[indices[i]];
//         i=indices[i];
//     }

//     for(auto x:indices){
//         cout<<x<<" ";
//     }
//     cout<<endl;

//     return ans;
// }
                
int max_sum_inc_subseq(vector<int> &V){
    int n=V.size();

    vector<int> mis=V; // stores max increasing subsequence's element sum ending at an index

    int ans=INT_MIN;

 
    int max_len=0;
    int idx=-1;

    int curr_ans=0;
    int flag=0;

    // for each increasing subsequence ending at the ith element we just need to change the add condition  
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(V[i] > V[j] && mis[j]+V[i] > mis[i] ){
                mis[i]= mis[j]+V[i];
            }
        }
    }

    for(auto x:mis){
        ans= max(x,ans);
    }

    return ans;
}


