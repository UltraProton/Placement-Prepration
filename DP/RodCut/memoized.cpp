#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int cut_rod(int n, vector<int> &prices, vector<int> &table);

int main(int argc, char const *argv[])
{
    vector<int> prices{0,1,5,8,9,10,17,17,20,24,30};
    vector<int> table(20,-1);

    cut_rod(10,prices,table);
    
    for(int i=1;i<=10;i++){
        //cout<<cut_rod(i,prices, table)<<endl;
        cout<<table[i]<<" ";
        
    }

    //cout<<cut_rod(5, prices, table);
    
    return 0;
}

int cut_rod(int n, vector<int> &prices,  vector<int> &table){
    if(table[n]>=0){
        return table[n];
    }

    if(n==0){
        return 0;
    }

    else{
        
        int q=INT_MIN;
        for(int i=1;i<=n;i++){
            q= max(prices[i]+ cut_rod(n-i,prices, table),q);
        }

        table[n]=q;
        return table[n];
    }
}
