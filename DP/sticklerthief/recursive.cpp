#include<bits/stdc++.h>

using namespace std;

int max_profit(vector<int> &Values, int l, int r);

int main(int argc, char const *argv[])
{
    /* code */
    int t=0;
    int n=0;
    int x=0;
    int c=0;
    vector<int> Values;
    cin>>t;
    while (t>0)
    {   
        Values.clear();

        cin>>n;
        c=0;
        while (c<n)
        {
            cin>>x;
            Values.emplace_back(x);
            c++;
        }
        cout<<max_profit(Values,0,n-1)<<endl;
        t--;
    }
    
    return 0;
}


int max_profit(vector<int> &Values, int l, int r){
    if(l>r){
        return 0;
    }

    if(l==r){
        return Values[l];
    }

    if(l+1==r){
        return max(Values[l], Values[r]);
    }

    else{
        return max(Values[l]+max_profit(Values,l+2,r), max_profit(Values,l+1,r));
    }
}