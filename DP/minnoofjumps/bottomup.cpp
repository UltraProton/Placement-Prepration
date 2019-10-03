#include<bits/stdc++.h>

using namespace std;

int min_no_of_jumps(vector<int> &V);

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
        cout<<min_no_of_jumps(V)<<endl;

        t--;
    }
    
    return 0;
}


int min_no_of_jumps(vector<int> &V){
    int n=V.size();
    vector<int> table(n,INT_MAX);//* Stores the min no of jumps needed to reach till an index from source

    //* table[i] stores min no of jumps needed to reach i from source 0 

    table[0]=0;//* No of jumps required to reach source from source is 0

    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            //* If we can reach i from j i.e we are at j + the no of jumps allowed from j (V[j]) is greater than i and the min no
            //* of jumps at i are more than the jumps we will have to take if we take jump from 'j'
            if(j+ V[j]>=i && table[i]> table[j] + 1){
                table[i]=table[j]+1;
            }
        }
    }

    return table[n-1];
}



