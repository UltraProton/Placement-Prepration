#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

ll rod_cut_recursive(vector<int> &prices,int n );

int main(){
    vector<int> prices{0,1,5,8,9,10,17,17,20,24,30};
    
    for(int i=1;i<=10;i++){
        cout<<rod_cut_recursive(prices,i)<<endl;
    }
    

    return 0;
}

ll rod_cut_recursive(vector<int> &prices, int n){
    if(n==0){
        return 0;
    }

    else{
        ll ans= INT_MIN;

        for(int i =1;i<=n;i++){
            ans= std::max(ans, prices[i]+ rod_cut_recursive(prices,n-i));
        }

        return ans;
    }
}