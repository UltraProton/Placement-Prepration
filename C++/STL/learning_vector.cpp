#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void show(vector<int> &);

void addEdge(vector<int> adj[], int u, int v){
	adj[u].push_back(v);
	adj[v].push_back(u);
}

void printGraph(vector<int> adj[]){
	for (int i = 0; i < 4; ++i)
		{
			cout <<"Adjacency list of vertex " << i<< endl;
			for(auto it: adj[i])
				cout << it << "->";

			cout <<"\n\n";
		}

	}


int main(int argc, char const *argv[])
{
    /*
	vector<int> adj[4];

	addEdge(adj,0,3);
	addEdge(adj,1,2);
	addEdge(adj,1,3);
	addEdge(adj,1,0);
	addEdge(adj,2,3);
	addEdge(adj,2,0);

	printGraph(adj);

	*/

	vector<int> v(12);

	cout << "capacity: " << v.capacity() <<'\n' << "size: " << v.size() << '\n' ;

	// Notice you can initialize a vector with a value during initialization or using vector.assign()
	vector<int> v1(5,10);

	vector<int> v2;

	v2.assign(6,7);

	show(v1);

	show(v2);

	return 0;
}


void show(vector<int> &x){
    for(auto p: x)
        cout<< p<< " ";
    cout << endl;
}
