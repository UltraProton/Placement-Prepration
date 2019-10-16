/* 
* If we use priority_queue of pair of int then then by default the elements are arranged according to the first value of the pair.
* We can have our own default order by declaring. 
! https://stackoverflow.com/questions/37318537/deciding-priority-in-case-of-pairint-int-inside-priority-queue

? To simplify our life we can say that the first element is key and second element is distance

 */


#include<bits/stdc++.h>

using namespace std;

void Dijkstra(vector<vector<pair<int,int>>> &adj, int src);

class compare_by_second{
    public:

    bool operator()(const pair<int, int> &p1, const pair<int,int> &p2){
        return p1.second > p2.second;
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    priority_queue<pair<int,int>, vector<pair<int,int>>, compare_by_second> Q;

    // Q.push(make_pair(1,2));
    // Q.push(make_pair(2,3));
    // Q.push(make_pair(4,5));
    // Q.push(make_pair(5,-1));
    // Q.push(make_pair(6,10));
    // Q.push(make_pair(7,2));
    // Q.push(make_pair(8,5));

    // while(!Q.empty()){
    //     cout<<Q.top().first<<" , "<<Q.top().second<<endl;
    //     Q.pop();
    // }


    vector<vector<pair<int,int>>> G(5);

    G[0].emplace_back(make_pair(1,10));
    G[0].emplace_back(make_pair(2,5));
    G[1].emplace_back(make_pair(2,2));
    G[1].emplace_back(make_pair(3,1));
    G[2].emplace_back(make_pair(1,3));
    G[2].emplace_back(make_pair(3,9));
    G[2].emplace_back(make_pair(4,2));
    G[3].emplace_back(make_pair(4,4));
    G[4].emplace_back(make_pair(3,6));
    
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
    vector<int> dist(V,INT_MAX);
    vector<int> processed(V,0);

    priority_queue<pair<int,int>, vector<pair<int,int>>, compare_by_second> Q; //? This class is passed here

    dist[src]=0;

    Q.push(make_pair(src,dist[src]));

    pair<int,int> curr;

    while (!Q.empty())
    {
        curr=Q.top();
        Q.pop();
        cout<<curr.first<<endl;
        processed[curr.first]=1;
        for(auto x:adj[curr.first]){
            if(processed[x.first]==0 &&   dist[x.first]> dist[curr.first]+ x.second ){
                dist[x.first]= dist[curr.first]+ x.second;
                Q.push(make_pair(x.first, dist[x.first]));
            }
        }
    }

    for(auto x:dist){
        cout<<x<<" ";
    }

}


