/* 

https://leetcode.com/problems/house-robber/submissions/

 */


#include<bits/stdc++.h>

using namespace std;

int max_profit(vector<int> &Values);

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
        
        cout<<max_profit(Values)<<endl;
        
        t--;
    }
    
    return 0;
}

int max_profit(vector<int> &Values){
    int n=Values.size();
    //* Actually we don't need this table at all because at any moment we just need 2 previous values
    // vector<int> table(n,0);
    // table[0]=Values[0];
    // table[1]= max(Values[0],Values[1]);
    int a=Values[0];
    int b=max(Values[0],Values[1]);
    int ans=0;
    for(int i=2;i<n;i++){
        ans=max(Values[i]+a,b);
        a=b;
        b=ans;
    }

    return ans;
}