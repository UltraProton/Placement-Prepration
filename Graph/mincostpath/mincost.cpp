/* https://practice.geeksforgeeks.org/problems/minimum-cost-path/0
 */
#include<bits/stdc++.h>

using namespace std;

class node{
    public:
    int x;
    int y;
    int dist;
    node(){}
    node(int x, int y, int d){
        this->x=x;
        this->y=y;
        this->dist=d;
    }
};

class compare{
    public:
    bool operator()(const node &n1 , const node &n2){
        // if(n1.dist > n2.dist){
        //     return true;
        // }
        // else{
        //     return false;
        // }
        //* better to write
        return n1.dist > n2.dist;
    }
};

int min_cost_path(vector<vector<int>> &G);
bool is_safe(int r, int c, int n);

int main(int argc, char const *argv[])
{
    /* code */
    int t=0;
    int n=0;
    vector<vector<int>> G;
    cin>>t;
    while (t>0)
    {
        cin>>n;

        G.clear();

        G=vector<vector<int>>(n,vector<int>(n,0));

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin>>G[i][j];
            }
        }

        cout<<min_cost_path(G)<<endl;

        t--;
    }
    
    // priority_queue<node, vector<node>, compare> Q;
    // Q.push(node(0,0,1));
    // Q.push(node(0,0,2));
    // Q.push(node(0,0,3));

    // while (!Q.empty())
    // {
    //     cout<<Q.top().dist<<endl;
    //     Q.pop();
    // }
    
    return 0;
}

/* 
* Solving this problem by assumming the distance of the edge between two reachable nodes is the value of the destination cell and 
* we update the distance. So this becomes a graph problem where we want to find the shortest path to destination [n-1,n-1] from the
* source [0,0]

 */ 
int min_cost_path(vector<vector<int>> &G){
    int n=G.size();

    if(n==1){
        return G[0][0];
    }

    vector<vector<int>> visited(n,vector<int>(n,0));
    vector<vector<int>> dist(n,vector<int>(n,1000000));

    priority_queue<node, vector<node>, compare> Q;
    
    vector<int> ROW{-1,1,0,0};
    vector<int> COL{0,0,-1,1};

    node src(0,0,G[0][0]);

    Q.push(src);

    node curr;

    int curr_row=0;
    int curr_col=0;
    int curr_dist=0;

    int r1=0;
    int c1=0;

    while(!Q.empty()){
        curr=Q.top();
        curr_row=curr.x;
        curr_col=curr.y;
        curr_dist=curr.dist;

        visited[curr_row][curr_col]=1;

        Q.pop();

        for(int i=0;i<4;i++){
            r1=curr_row+ROW[i];
            c1=curr_col+COL[i];
            if(is_safe(r1,c1,n) && visited[r1][c1]==0){
                if(dist[r1][c1] > G[r1][c1] + curr_dist){
                    dist[r1][c1]=G[r1][c1] + curr_dist;
                    Q.push(node(r1,c1,dist[r1][c1]));

                    // if(r1==n-1 && c1==n-1){
                    //     return dist[r1][c1];
                    // }
                }            
            }
        }
    }

    // for(auto vec:dist){
    //     for(auto ele: vec){
    //         cout<<ele<<" ";
    //     }
    //     cout<<endl;
    // }

    return dist[n-1][n-1];
}


bool is_safe(int r, int c, int n){
    if(r>=0 && r < n && c >=0 && c < n){
        return true;
    }

    else{
        return false;
    }
}