/* 
https://practice.geeksforgeeks.org/problems/find-whether-path-exist/0

 */

#include<bits/stdc++.h>

using namespace std;

bool path_exists(vector<vector<int>> &G);
bool is_safe(int r, int c, int m ,int n);

int main(int argc, char const *argv[])
{
    /* code */
    int t=0;
    int n=0;
    int x=0;
    vector<vector<int>> G;

    cin>>t;

    while (t>0)
    {   
        G.clear();

        cin>>n;

        G=vector<vector<int>>(n,vector<int>(n,0));

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin>>G[i][j];
            }
        }

        cout<<path_exists(G)<<endl;

        t--;
    }
    
    return 0;
}

//* There is a path between two cells if they are reachable from each other
bool path_exists(vector<vector<int>> &G){
    pair<int,int> src;
    queue<pair<int,int>> Q;
    vector<int> ROW{0,0,1,-1};
    vector<int> COL{-1,1,0,0};
    int n=G.size();
    
    vector<vector<int>> visited(n,vector<int>(n,0));

    //Find the position of source in the graph
    for(int i=0;i<G.size();i++){
        for(int j=0;j<G[0].size();j++){
            if(G[i][j]==1){
                src=pair<int,int>{i,j};
            }
        }
    }

    //* Push the source vertex in the graph
    Q.push(src);

    pair<int,int> curr;
    int curr_row=0;
    int curr_col=0;

    int r=0;
    int c=0;
    bool flag=0;

    while(!Q.empty()){
        curr= Q.front();
        Q.pop();
        curr_row=curr.first;
        curr_col= curr.second;
        // current cell is finished
        visited[curr_row][curr_col]=1;
        // for each adjacent cell in the direction left, right, up and down
        for(int i=0;i<4;i++){
            r=curr_row+ ROW[i];
            c= curr_col+ COL[i];
            //* find if the cell is safe i.e it has valid indices and it is not visited
            if(is_safe(r,c,G.size(),G[0].size()) && visited[r][c]==0){
                //* If the adjacent cell has value of 2 then we have found the destination
                if(G[r][c]==2){
                    return true;
                }
                //* If the adjacent cell has value 3 then we can explore this cell in future calls
                else if(G[r][c]==3){
                    flag=1;//* We have a possibility of finding the path
                    Q.push(make_pair(r,c));
                }
            }
        }
        //* If the flag didn't become 1 and the control didn't return then we had only zeros in all the adjacent cell meaning we
        //* will not be able to find to destination from the source
        if(flag==0){
            return false;
        }
    }

    //* We are done exploring so we didn't return true anywhere. It means we will not be able to find the path to destination

    return false;
}

bool is_safe(int r, int c, int m, int n){
    if(r>=0 && r < m && c >=0 && c < n){
        return true;
    }
    else{
        return false;
    }
}