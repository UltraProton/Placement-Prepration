#include<bits/stdc++.h>

using namespace std;

int optimal_strategy(vector<int> &arr);

int main(int argc, char const *argv[])
{
    /* code */
    int t=0;
    int n=0;
    int x=0;
    vector<int> S;
    cin>>t;
    int i=0;
    while(t>0){
        cin>>n;
        i=n;
        S.clear();
        while(i>0){
            cin>>x;
            S.emplace_back(x);
            i--;
        }

    
        cout<<optimal_strategy(S)<<endl;

        // for(auto vec: memo){
        //     for(auto ele: vec){
        //         cout<<ele<<" ";
        //     }
        //     cout<<endl;
        // }

        t--;
    }
    
    return 0;
}


int optimal_strategy(vector<int> &arr){
    int n=arr.size();
    int l=0;
    int r=0;
    int x=0;
    int y=0;
    int z=0;
    vector<vector<int>> table(n,vector<int>(n,0));
    //* This is one of the unique ways of filling the table i.e filling the table diagonally like table is filled in matrix
    //* chain multiplication , longest palindromic subsequence but there we use 3 loops here the idea is bit different
    for(int gap=0;gap<n;gap++){
        //* i will start from the left end and j will be from the right end where (j-i)=gap. So for instance if the gap is 1 then
        //* this gap of one is maintained throughout the inner loop and the values filled are [0,1], [1,2], [2,3] ...[n-1,n]
        for(int i=0, j=gap; j<n; i++, j++){
            //* If there are only 2 elements we are considering then it will will be the max of 2 in the optimal strategy
            //* Note that even if we don't handle the this case here it will be handled by the below else so we can just write
            //* the statements in the else part and ignoring this if else altogether. If you don't get it use paper and pen and 
            //* see if we don't have the following if and just have statements in else and the gap is 1 then what will be the value
            //* at table[i][j]
            if(i+1==j){
                table[i][j]= max(arr[i],arr[j]);
            }
            //* Otherwise we should go for the choices which are optimal for us
            else{

                x= (i+2<=j)?(table[i+2][j]):0;

                y= (i+1<=j-1)? table[i+1][j-1] :0;

                z= (i<=j-2) ? table[i][j-2] : 0;

                table[i][j]= max(arr[i]+ min(x,y), arr[j]+min(y,z));    
            }
        }
    }

    //* We will get the ans at table[0][n-1]
    return table[0][n-1];
}
