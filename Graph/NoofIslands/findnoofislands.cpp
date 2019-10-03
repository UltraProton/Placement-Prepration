#include<bits/stdc++.h>

using namespace std;

int n_islands(vector<vector<int>> &G);
void n_islands_helper(vector<vector<int>> &G, vector<vector<int>> &Visited, int row, int col, vector<int> &ROW, vector<int> &COL);
bool is_safe(int row , int col, int m, int n);

int main(int argc, char const *argv[])
{
    /* code */
    int t=0;
    int n=0;
    int m=0;
    int i=0;
    int j=0;
    vector<vector<int>> Graph;
    cin>>t;
    while(t>0){
        cin>>n;
        cin>>m;

        Graph.clear();

        Graph= vector<vector<int>>(n,vector<int>(m,0));

        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                cin>>Graph[i][j];
            }
        }

        cout<<n_islands(Graph)<<endl;

        // for(auto vec:Graph){
        //     for(auto ele: vec){
        //         cout<<ele<<" ";
        //     }
        //     cout<<endl;
        // }

        t--;
    }

    return 0;
}

int n_islands(vector<vector<int>> &G){
    int m=G.size();
    int n=G[0].size();
    int ans=0;
    vector<vector<int>> visisted(m,vector<int>(n,0));
    vector<int> ROW{-1,-1,-1,0,0,1,1,1};
    vector<int> COL{-1,0,1,-1,1,-1,0,1};

    
    for(int i=0;i<m;i++){
        for(int j=0 ;j<n;j++){
            //* If the cell is not visited and it has a one then we found a new cluster which may grow so start exploring it
            if(!visisted[i][j] && G[i][j]==1){
                n_islands_helper(G,visisted,i,j,ROW, COL);
                ans++;
            }
        }
    }

    return ans;
}

void n_islands_helper(vector<vector<int>> &G, vector<vector<int>> &Visited, int row , int col, vector<int> &ROW, vector<int> &COL){
    Visited[row][col]=1;

    for(int i=0;i<8;i++){
        if(is_safe(row+ROW[i], col+COL[i], G.size(), G[0].size()) && Visited[row+ ROW[i]][col+COL[i]]==0 && G[row+ROW[i]][col+COL[i]]==1){
            n_islands_helper(G, Visited, row+ROW[i], col+COL[i], ROW, COL);
        }
    }
}

bool is_safe(int row, int col, int m, int n){
    if(row>=0 && row <m && col>=0 && col< n){
        return true;
    }
    return false;
}
