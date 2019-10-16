#include<bits/stdc++.h>

using namespace std;

int min_jumps(vector<int> &arr, int i, int n);

int main(int argc, char const *argv[])
{
    /* code */
    vector<int> V;
    int t=0,n=0,x=0;
    cin>>t;

    while(t>0){
        V.clear();
        cin>>n;
        while(n>0){
            cin>>x;
            V.emplace_back(x);
            n--;
        }

        // for(auto ele: V){
        //     cout<<ele<<" ";
        // }
        int ans=INT_MAX;
        cout<<min_jumps(V, 0, V.size())<<endl;

        t--;
    }
    return 0;
}

int min_jumps(vector<int> &arr, int i, int n){
    cout<<i<<","<<n<<endl;
    if(n<=0  || i>=arr.size() || i==n){
        return 0;
    }

    if(arr[i]==0){
        return INT_MAX;
    }


    else{
        int ans= INT_MAX;
        //* for each possibility of jump from the current position in the array
        for(int k=1;k<=arr[i];k++){
            //cout<<'x'<<endl;
            int jumps= min_jumps(arr,k+i,n-k-i);
            if(jumps!=INT_MAX && jumps + 1 < ans ){
                ans=jumps+1;
            }
        }

        return ans;
    }
}