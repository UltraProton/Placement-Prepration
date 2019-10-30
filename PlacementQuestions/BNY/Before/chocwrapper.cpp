#include<bits/stdc++.h>

using namespace std;

int choc_wrapper(int choc, int price, int wrap);

int main(int argc, char const *argv[])
{
    /* code */
    int t=0;
    int money=0, price=0, wrap=0;

    cin>>t;
    while (t>0)
    {
        cin>>money>>price>>wrap;
        cout<<choc_wrapper(money,price,wrap)<<endl;
        t--;
    }
    
    return 0;
}

int choc_wrapper(int money, int price, int wrap){
    int ans=0;
    ans= money/price;

    ans= ans + (ans-1)/(wrap-1);

    return ans;
}
