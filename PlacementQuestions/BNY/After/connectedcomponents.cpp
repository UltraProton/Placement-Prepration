#include<bits/stdc++.h>

using namespace std;

int dfs(vector<vector<int>> &G, int src, vector<int> &visited);

int main(){
	vector<string> edges;
	int n=0;
	
    cin>>n;

	vector<vector<int>> G(n+1);

	edges.emplace_back("1 2");
	edges.emplace_back("2 3");
	edges.emplace_back("3 4");
	edges.emplace_back("4 2");
	edges.emplace_back("7 8");
	//edges.emplace_back("");

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
			//cout<<u<<","<<v;
            //cout<<endl;
            G[u].emplace_back(v);
            G[v].emplace_back(u);
		}
	}

	vector<int> sizes;
	vector<int> visited(n+1,0);

	for(int i=1;i<=n;i++){
		if(!visited[i]){
			int curr= dfs(G,i,visited);
			sizes.emplace_back(curr);
		}
	}

	for(auto x: sizes){
		cout<<x<<endl;
	}

	return 0;
}

int dfs(vector<vector<int>> &G, int src,vector<int> &visited){
	visited[src]=1;
	int ans=0;
	for(auto u: G[src]){
		if(!visited[u]){
			ans+=dfs(G,u,visited);
		}
	}

	ans+=1;
	return ans;
}