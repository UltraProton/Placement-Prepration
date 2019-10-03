#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class graph{
	int V;
	vector<int> *adj;
	vector<int> visited;
	/* below vector's are to be used by DFS */
	vector<int> start_time;
	vector<int> finish_time;

public:
	graph(int V);

	void addEdge(int u, int v);

	void printGraph();
	void BFS(int source);
	void DFS();
	void DFS_Util(int source,int &time);
	void print_DFS_info();
};

int main(int argc, char const *argv[])
{

	graph g(6);

    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(2,1);
    g.addEdge(1,3);
    g.addEdge(3,2);
    g.addEdge(4,3);
    g.addEdge(4,5);
    g.addEdge(5,5);

	//g.printGraph();

	//g.BFS(0);

	g.DFS();

	g.print_DFS_info();

	return 0;
}



graph :: graph(int V){
	this->V =V;

	// adj is a pointer to an array of vectors of integers
	adj= new(nothrow) vector<int> [V];

	if(!adj){
		cout <<"insufficient memory" <<endl;
		return;
	}
}

void graph:: DFS(){
	visited= vector<int>(V,0);
	start_time= vector<int> (V,0);
	finish_time= vector<int> (V,0);
	
	int time=0;

	for(int i=0;i<V;i++){
		if(!visited[i]){
			DFS_Util(i,time);
		}
	}
}

void graph :: DFS_Util(int src,int &time){
	visited[src]=1;
	time=time+1;
	start_time[src]=time;
	
	cout<<src<<endl;

	for(auto x:adj[src]){
		if(!visited[x]){
			DFS_Util(x,time);
		}
	}

	time=time+1;
	finish_time[src]=time;
}

void graph :: print_DFS_info(){
	for(int i=0;i<V;i++){
		cout<<"Vertex: "<<i<<" "<<"start time: "<<start_time[i]<<" finish time: "<<finish_time[i]<<endl;
	}
}

void graph:: addEdge(int u, int v){

	adj[u].push_back(v);
	//adj[v].push_back(u);
}

void graph :: printGraph(){
	for (int i = 0; i < V; ++i)
		{
			cout <<"Adjacency list of vertex " << i<< endl;
			for(auto it: adj[i])
				cout << it << "->";

			cout <<"\n\n";
		}

	}

void graph:: BFS(int source){
	//bool *visited= new(nothrow) bool [V];

	int *color= new(nothrow) int[V];
	int *parent= new(nothrow) int[V];
	int *distance= new(nothrow) int[V];

	if(!color || !parent || !distance){
		cout <<"Memory insufficient." <<endl;
		return;
	}

	// initialization of all the above arrays where all the vertices are colored white and distance of every vertex except
	// source is set to infinity
	for (int i = 0; i < V; ++i)
	{
		if(i!=source){
			color[i]='w';
			parent[i]=-100;
			distance[i]= 10000;
		}
	}

	// At start of BFS source is colored grey which indicates that the source is discovered and distance from source
	//  is set to 0
	color[source]= 'g';
	distance[source]=0;

	// c++ queue of integers...
	// To-do: Revise c++ queue and its operations
	// we can make use of list or vector also to be used as queue
	// enqueue and dequeue are push and pop operations in c++ queue
	queue<int> Q;

	Q.push(source);

	while(!Q.empty()){
		int current=  Q.front();
		Q.pop();

		for(auto it: adj[current]){
			if(color[it]=='w'){
				color[it]= 'g';
				distance[it] = distance[current]+1;
				parent[it]= current;

				Q.push(it);
			}
		}

		color[current]='b';
	}

	for (int i = 0; i < V; ++i)
	{
		printf("Vertex : %d Parent: %d Distance from source: %d \n",i, parent[i], distance[i]);
	}

	// remember that [] comes first before the name of the array to be deallocated using delete operator in cpp
	delete []color;
	delete []distance;
	delete []parent;
	delete [] adj;

}


