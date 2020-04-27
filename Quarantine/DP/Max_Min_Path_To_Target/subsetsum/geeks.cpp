#include<bits/stdc++.h>
using namespace std;
int main()
 {
	//code
	int t=0;
	int n=0;
	int x=0;
	int sum=0;
	cin>>t;
	while(t>0){
	    cin>>n;
	    vector<int> s;
	    sum=0;
	    for(int i=0;i<n;i++){
	        cin>>x;
	        sum+=x;
	        s.emplace_back(x);
	    }
	    
        //cout<<sum<<endl;
	    //Algorithm
	    if(sum&1){
	        cout<<"NO"<<endl;
	        t--;
	        continue;
	    }

	    int m=s.size();
	    int ss=sum/2;
	    
	    vector<vector<int>> dp(m+1,vector<int>(ss+1,0));
	    dp[0][0]=1;
	    for(int i=1;i<=m;i++){
	        for(int j=1;j<=ss;j++){
	            if(j-1==0){
	                dp[i][j-1]=1;
	                continue;
	            }
	            dp[i][j]=dp[i-1][j];
	            
	            if(j-s[i-1]>=0){
	                dp[i][j]= (dp[i][j] || dp[i-1][j-s[i-1]]);
	            }
	        }
	    }
	    if(dp[m][ss]==1){
	        cout<<"YES";
	    }
        else{
            cout<<"NO";
        }
	    cout<<endl;
	    t--;
	}
	return 0;
}