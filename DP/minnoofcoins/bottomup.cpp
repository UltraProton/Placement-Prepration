#include<bits/stdc++.h>

using namespace std;

int min_coins(vector<int> & coins , int target);

int main(int argc, char const *argv[])
{
    /* code */
    int t=0,v=0,n=0,x=0,y=0;
    vector<int> V;
    cin>>t;
    while(t>0){
        V.clear();
        cin>>v;
        cin>>n;
        y=n;

        while(y>0){
            cin>>x;
            V.emplace_back(x);
            y--;
        }

        cout<<min_coins(V,v)<<endl;

        t--;
    }

    return 0;
}


int min_coins(vector<int> & coins , int target){
    //vector<int> table(target+1,INT_MAX);
    int table[target+1];
    
    for(int i=1;i<=target;i++){
        table[i]=INT_MAX;
    }  
    
    table[0]=0;//* We need 0 coins to make a change for target 0

    
    for(int t=1;t<=target;t++){
        for(int j=0;j<coins.size();j++){  
            if(coins[j]<=t){
                int sub_res=table[t-coins[j]]; 
                if(sub_res!=INT_MAX && sub_res +1 < table[t]){
                    //ans= min(ans, 1+ table[t-coins[j]]);
                    table[t]=sub_res+1;
                }
            }
        }
    }


    // for(auto x:table){
    //     cout<<x<<" ";
    // }
    
    return table[target];
}
