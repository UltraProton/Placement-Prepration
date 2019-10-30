#include <bits/stdc++.h>

using namespace std;

int remove_adj(vector<int> &arr);

int main(void) {
	// your code goes here
	int n=0;
	cin>>n;
	vector<int> arr;
	int x=0;
	while(n>0){
	   cin>>x;
	   arr.emplace_back(x);
	   n--;
	}
	
// 	for(auto x:arr){
// 	    cout<<x<<" ";
// 	}
	cout<<endl;
	
	cout<<remove_adj(arr)<<endl;
	
	return 0;
}


int remove_adj(vector<int> &arr){
    stack<int> st;
    for(auto x: arr){
        if(st.empty() || st.top()!=x){
            st.push(x);
        }
        else if(st.top()==x){
            st.pop();
        }
    }
    
    return st.size();
}

