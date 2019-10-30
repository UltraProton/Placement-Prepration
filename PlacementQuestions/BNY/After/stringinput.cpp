#include<bits/stdc++.h>

using namespace std;

int main(){
	vector<string> edges;
	int n=0;
	
    cin>>n;

	vector<vector<int>> G(n+1);

	edges.emplace_back("1 9");
	edges.emplace_back("100 2");
	edges.emplace_back("50 2");
	edges.emplace_back("12 7");
	edges.emplace_back("13 6");
	edges.emplace_back("41 5");

	int u= 0;
	int v=0;

	for(auto e: edges){
		//find() will give the index of the starting of the first occurrence of the string to be searched
		int l= e.find(" ");
		if(l!=string::npos){
			string x= e.substr(0,l);
			u= stoi(x);
			//erase the delimeter from the string
			e.erase(0,l+1);
			string y= e;
			v= stoi(y); 
			cout<<u<<","<<v;
            cout<<endl;
		}
	}
    
}