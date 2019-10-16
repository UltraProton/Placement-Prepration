#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class graph{
	int V;
	list<int> *adj;

public:
	graph(int V);

	void addEdge(int u, int v);

	void printGraph();

	void BFS(int source);

	void DFS();

	void DFSUtil(vector<int> &, vector<int> &, vector<int> &, vector<int> &, int, int &);

	void printBFSPath(int source, int dest);

};


graph :: graph(int V){
	this->V =V;

	// allocating an array of list of integers of size V
	adj= new(nothrow) list<int> [V];

	if(!adj){
		cout <<"insufficient memory" <<endl;
		return;
	}
}

void graph:: printBFSPath(int source, int dest){
	// A default value can be assigned to vectors during initialization in the following ways

	// parent is a vector of -100 stored V times
	std::vector<int> parent(V,-100);

	// color is a vector of 'w' stored V times in the color
	std::vector<char> color(V,'w');

	color[source]= 'g';
	//distance[source]=0;

	// list offers lots of functions
	list<int> queue;

	queue.push_back(source);

	while(!queue.empty()){
		int current=  queue.front();
		queue.pop_front();

		for(auto it: adj[current]){
			if(color[it]=='w'){
				color[it]= 'g';
				//distance[it] = distance[current]+1;
				parent[it]= current;

				queue.push_back(it);
			}

			color[current]='b';
		}
	}

	// Backtracking from destination to source after running a BFS on the graph
		int current= dest;

		while(current!=-100){
			if(source==current)
				printf("%d->\n",source);

            // If during backtracking we find any -100 then no path exists between the source and destination
			else if(parent[current]== -100){
				printf("No path from source : %d to dest: %d exists\n",source,dest);
			}

			else
				printf("%d->",current);

			current= parent[current];
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

	for (int i = 0; i < V; ++i)
	{
		if(i!=source){
			color[i]='w';
			parent[i]=-100;
			distance[i]= 10000;
		}
	}

	color[source]= 'g';
	distance[source]=0;
	parent[source]=-1000;

	list<int> queue;

	queue.push_back(source);

	while(!queue.empty()){
		int current=  queue.front();
		queue.pop_front();

		for(auto it: adj[current]){
			if(color[it]=='w'){
				color[it]= 'g';
				distance[it] = distance[current]+1;
				parent[it]= current;

				queue.push_back(it);
			}

			color[current]='b';
		}
	}

	for (int i = 0; i < V; ++i)
	{
		printf("Vertex : %d Parent: %d Distance from source: %d \n",i, parent[i], distance[i]);
	}

	delete []color;
	delete []distance;
	delete []parent;
	delete [] adj;

}

void graph::DFSUtil(vector<int> &parent, vector<int> &discovery, vector<int> &finishing, vector<int> &color, int vertex, int & time){

    //  Base case:
	if(color[vertex]=='b')
		return;


	time= time +1;
	color[vertex]= 'g';
	discovery[vertex]= time;
	cout<<vertex<<endl;

	for (auto i: adj[vertex])
	{
		if (color[i]=='w')
		{
			parent[i]= vertex;

			DFSUtil(parent, discovery, finishing,color, i, time);
		}
	}

	color[vertex]='b';
	time= time+1;
	finishing[vertex]= time;
}


void graph:: DFS(){
    // initializing vectors in a single instruction
	vector<int> color(V,'w');
	vector<int> parent(V,-100);
	vector<int> distance(V,10000);
	vector<int> discovery(V,0);
	vector<int> finishing(V,0);

	int time=0;

	/*int *color= new(nothrow) int[V];
	int *parent= new(nothrow) int[V];
	int *distance= new(nothrow) int[V];
	int *discovery= new(nothrow) int[V];
	int *finishing = new(nothrow) int[V];

	int time=0;

	for(int i=0; i < V;i++)
	{
		color[i]='w';
		parent[i]=-100;
		distance[i]=10000;
		discovery[i]= 0;
		finishing[i]= 0;
	}

	*/

/*for (int i = 0; i < V; ++i)
	{
		if(color[i]=='w')
			DFSUtil(parent,discovery, finishing,color,i,time);
	}
  */
  
    DFSUtil(parent,discovery, finishing,color,4,time);
	
	for (int i = 0; i < V; i++)
	{
		cout << "node: "<<i<<" parent: " << parent[i] << "  discovery at: " << discovery[i] << "  finishing at: " << finishing[i]<< "\n\n";
	}

}


int main(int argc, char const *argv[])
{

	graph g(8);

	g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(4, 0);
    g.addEdge(2, 1);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(3, 2);
    g.addEdge(2, 5);
    g.addEdge(5, 5);
    g.addEdge(5, 6);
    g.addEdge(6, 7);
    g.addEdge(7, 6);


	//g.printGraph();
	//cout <<"\n\n";

	//g.printBFSPath(0,3);

	//cout <<"\n\n";

	g.BFS(4);

	//g.DFS();

	return 0;
}
