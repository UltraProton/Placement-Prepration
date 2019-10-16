/* 
https://practice.geeksforgeeks.org/problems/shortest-source-to-destination-path/0

 */

#include<bits/stdc++.h>

using namespace std;

int path_exists(vector<vector<int>> &G, pair<int,int> &dest);
bool is_safe(int r, int c, int m ,int n);

int main(int argc, char const *argv[])
{
    /* code */
    int t=0;
    int n=0,m=0;
    int x=0;
    vector<vector<int>> G;
    
    cin>>t;

    while (t>0)
    {   
        G.clear();

        cin>>n;
        cin>>m;

        G=vector<vector<int>>(n,vector<int>(m,0));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>G[i][j];
            }
        }

        pair<int,int> dest;

        cin>>dest.first>>dest.second;

        cout<<path_exists(G,dest)<<endl;

        t--;
    }
    
    return 0;
}

//* There is a path between two cells if they are reachable from each other
int path_exists(vector<vector<int>> &G, pair<int,int> &dest){
    pair<pair<int,int>,int> src;
    queue<pair<pair<int,int>,int>> Q;
    vector<int> ROW{0,0,1,-1};
    vector<int> COL{-1,1,0,0};
    int n=G.size();
    
    vector<vector<int>> visited(n,vector<int>(n,0));

    src=make_pair(make_pair(0,0),0);

    //* Push the source vertex in the graph
    Q.push(src);

    pair<pair<int,int>,int> curr;
    int curr_row=0;
    int curr_col=0;
    int curr_dist=0;
    int r=0;
    int c=0;
    bool flag=0;

    while(!Q.empty()){
        curr= Q.front();
        Q.pop();
        curr_row=curr.first.first;
        curr_col= curr.first.second;
        curr_dist=curr.second;
        // current cell is finished
        visited[curr_row][curr_col]=1;
        // for each adjacent cell in the direction left, right, up and down
        for(int i=0;i<4;i++){
            r=curr_row+ ROW[i];
            c= curr_col+ COL[i];
            //* find if the cell is safe i.e it has valid indices and it is not visited
            if(is_safe(r,c,G.size(),G[0].size()) && visited[r][c]==0 && G[r][c]==1){
                if(r==dest.first && c==dest.second){
                    return 1+ curr_dist;
                }
                else{
                    Q.push(make_pair(make_pair(r,c),curr_dist+1));
                }
            }
        }
    }

    return INT_MAX;
}

bool is_safe(int r, int c, int m, int n){
    if(r>=0 && r < m && c >=0 && c < n){
        return true;
    }
    else{
        return false;
    }
}