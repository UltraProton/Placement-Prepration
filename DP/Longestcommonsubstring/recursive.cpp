/* 
* The memoized version of this is going to be hard because we are saving the answer in a count variable in the recursion. 

*/

#include<bits/stdc++.h>

using namespace std;

int lc_substr(string &s1, string &s2, int m, int n, int count);

int main(int argc, char const *argv[])
{
    string s1;
    string s2;
    int t=0;
    int n=0;
    int m=0;

    cin>>t;

    while(t>0){
        s1.clear();
        s2.clear();
        cin>>m;
        cin>>n;
        cin>>s1;
        cin>>s2;
        cout<<lc_substr(s1,s2,m,n,0)<<endl;
    
        t--;
    }

    
    return 0;
}

int lc_substr(string &s1, string &s2, int m, int n, int count){
    cout<<m<<","<<n<<","<<count<<endl;
    //last characters in the suffix don't match
    if(m==0 || n==0){
        return count;
    }
 
    //last characters in the suffix match

    if(s1[m-1]==s2[n-1]){
        count =lc_substr(s1,s2,m-1,n-1,count+1);
    }

    //try different suffixes starting at different indices from 1<=i<=m in s1 and 1<=j<=n in s2
    else{
        count= max(lc_substr(s1,s2,m-1,n,0), lc_substr(s1,s2,m,n-1,0));
        return count;
    }

}


/* "abcdxyz";  
Y = "xyzabcd";  */