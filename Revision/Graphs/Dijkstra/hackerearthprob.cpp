#include<bits/stdc++.h>

using namespace std;

// To be stored in the graph
class vertex{
    public:
    int id;
    int w;
    vertex(){};
    vertex(int id, int w): id(id), w(w){}
};

// To be stored in the queue
class queue_node{
    public: 
    int id;
    int dist;
    queue_node(){}
    queue_node(int id, int dist): id(id), dist(dist){}
};

// For comparing the queue node
class compare{
    public:
    bool operator()(queue_node &x, queue_node &y){
        return x.dist > y.dist;
    }
};


void dijkstra(vector<vector<vertex>> &G, int src, int n);

int main(int argc, char const *argv[])
{
    /* code */
    
    int src=1;
    int n=0;
    int m=0;

    int i=0;
    int a=0;
    int b=0;
    int w=0;

    cin>>n>>m;

    vector<vector<vertex>> G(n+1);
    
    while (i<m)
    {   
        cin>>a;
        cin>>b;
        cin>>w;
        G[a].emplace_back(vertex(b,w));
        i++;
    }

    int u=0;

    dijkstra(G,src,n);

    return 0;
}



void dijkstra(vector<vector<vertex>> &G, int src, int n){
    vector<int> dist(100000,2000);

    priority_queue<queue_node,vector<queue_node> , compare> Q;

    // for(int i=1;i<5;i++){
    //     Q.push(queue_node(i,rand()%100));
    // }

    // queue_node x;
    // while(!Q.empty()){
    //     x=Q.top();
    //     cout<<x.id<<","<<x.dist<<endl;
    //     Q.pop();
    // }

    vector<int> processed(100000,0);
    
    dist[src]=0;

    queue_node curr(src, 0);

    Q.push(curr);

    while (!Q.empty())
    {
        curr=Q.top();
        Q.pop();
        processed[curr.id]=1;
        //cout<<dist[curr.id]<<endl;
        //cout<<curr.dist<<endl;
        
        for(auto v: G[curr.id]){
            if(processed[v.id]==0 && dist[v.id] > dist[curr.id] + v.w){
                dist[v.id]= dist[curr.id] +v.w;
                Q.push(queue_node(v.id,dist[v.id]));
            }
        }   
    }

    for(int i=2;i<=n;i++){
        cout<<dist[i]<<" ";
    }
}