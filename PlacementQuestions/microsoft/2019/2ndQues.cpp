#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

long double fun(vector<vector<ll>> &points, int x, int s){
    long double ans=0;
    long double temp=0;
    for(int i=0;i<x;i++){
        for(int j=i+1;j<x;j++){
            temp= (int)(pow(abs(points[0][i]-points[0][j]),2)+0.5) + (int)(pow(abs(points[1][i]-points[1][j]),2)+0.5);
            if(ans < temp){
                ans=temp;
            }
        }
    }

    //cout<<ans<<endl;

    temp= ans/double(s);

    ll  mant= int(temp);
    ll ex= double(temp-mant)*10000000;

    ex=ex/10;

    ex=roundf(ex);


    //cout<<temp<<endl;

    return ans;
}


int main(){

    vector<vector<ll>> p;

    p.emplace_back(vector<ll>{1,2,3,4,145454989758});
    p.emplace_back(vector<ll>{4,5,6,7,343955998977});

    fun(p,5,7);

    // for(int i=0;i<p[0].size();i++){
    //     cout<<p[0][i]<<','<<p[1][i]<<endl;
    // }

    return 0;
}


//     float in=1.464799;
//     int mant= int(in);
//     int ex= (float)(in-mant)*1000000;
   
//     float n=ex;
    
//     cout<<n<<endl;

//     n=n/10;

//     cout<<n<<endl;
    
//     n=roundf(n);

//     cout<<n<<endl;
    
//     n=(float)mant*100000+n;

//     cout<<n<<endl;
    
//     cout<<n/100000;
