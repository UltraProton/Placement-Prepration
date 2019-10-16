#include<bits/stdc++.h>

using namespace std;

int longest_bitonic_subsequence(vector<int> &V);

int main(int argc, char const *argv[])
{
    /* code */
    vector<int> V{1,11,2,10,4,5,2,1};

    int t=0;
    int n=0;
    int x=0;
    
    cin>>t;

    while(t>0){
        V.clear();
        cin>>n;
        while(n>0){
            cin>>x;
            V.emplace_back(x);
            n--;
        }

        cout<<longest_bitonic_subsequence(V)<<endl;

        t--;
    }

    return 0;
}

int longest_bitonic_subsequence(vector<int> &V){
    int n=V.size();
    vector<int> LIS(n,1); // stores the longest increasing subseqence ending at an index
    vector<int> LDS(n,1);// stores the longest decreasing subsequence starting at an index
    
    //find the lis of the input 
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(V[i] > V[j] && LIS[i] < LIS[j]+1){
                LIS[i]=LIS[j]+1;
            }
        }
    }

    //find the lds of the input
    for(int i=n-2;i>=0;i--){
        for(int j=n-1;j>i;j--){
            if(V[i] > V[j] && LDS[i] < LDS[j]+1){
                LDS[i]=LDS[j]+1;
            }
        }
    }

    //find the length of longest bitonic subsequence
    //* Note that at any index the lis includes as well as lds also includes the element at index so our ans is 
    //* len(lis[i]) + len(lds[i]) -1

    int ans=INT_MIN;

    for(int i=0;i<n;i++)
    {   //cout<<LIS[i]<<" , "<<LDS[i]<<endl;
        ans= max(ans, LIS[i]+LDS[i]-1);
    }

    return ans;

}


