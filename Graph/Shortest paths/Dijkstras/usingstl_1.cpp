/* 
! https://stackoverflow.com/questions/37318537/deciding-priority-in-case-of-pairint-int-inside-priority-queue
 */


#include<bits/stdc++.h>

using namespace std;

void Dijkstra(vector<vector<pair<int,int>>> &adj, int src);

// You have to write this class to make priority queue work as min priority queue
class compare{
    public:
    bool operator()(const pair<int,int> &p1 , const pair<int,int> &p2){
        return p1.first > p2.first;
    }
};

int main(int argc, char const *argv[])
{

    vector<vector<pair<int,int>>> G(5);

    G[0].emplace_back(make_pair(10,1));
    G[0].emplace_back(make_pair(5,2));
    G[1].emplace_back(make_pair(2,2));
    G[1].emplace_back(make_pair(1,3));
    G[2].emplace_back(make_pair(3,1));
    G[2].emplace_back(make_pair(9,3));
    G[2].emplace_back(make_pair(2,4));
    G[3].emplace_back(make_pair(4,4));
    G[4].emplace_back(make_pair(6,3));
    
    for(auto vec: G){
        for(auto ele: vec){
            cout<<ele.first<<" ," <<ele.second<<" ";
        }
        cout<<endl;
    }

    Dijkstra(G,0);

    return 0;
}

void Dijkstra(vector<vector<pair<int,int>>> &adj, int src){
    int V= adj.size();
    vector<int> parent(V,-1);
    vector<int> dist(V,10000);
    priority_queue<pair<int,int>, vector<pair<int,int>>, compare> Q;
    vector<int> processed(V,0);

    dist[src]=0;

    Q.push(make_pair(dist[src],src));

    pair<int,int> curr;

    while (!Q.empty())
    {
        curr=Q.top();
        Q.pop();
        cout<<curr.second<<endl;
        processed[curr.second]=1;
        for(auto x:adj[curr.second]){
            if(processed[x.second]==0 &&   dist[x.second]> dist[curr.second]+ x.first ){
                dist[x.second]= dist[curr.second]+ x.first;
                Q.push(make_pair(dist[x.second],x.second));
            }
        }
    }

    for(auto x:dist){
        cout<<x<<" ";
    }
}


