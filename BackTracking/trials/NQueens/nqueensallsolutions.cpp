#include<bits/stdc++.h>

using namespace std;

bool is_safe(vector<vector<int>> &Grid, int n, int row, int col);
void solve(vector<vector<int>> &Grid, int n, int row);
void print_grid(vector<vector<int>> &Grid);

int main(int argc, char const *argv[])
{
    vector<vector<int>> Grid(4,vector<int>(4,0));
    solve(Grid, 4,0);
    //print_grid(Grid);

    return 0;
}

/* 
is_safe() is called when the rows till row-1 are already filled. So we need to check the upper left diagonal, 
upper right diagonal and the column col 

*/

bool is_safe(vector<vector<int>> &Grid, int n, int row, int col){
    //check if the col is safe
    for(int i=row;i>=0;i--){
        if(Grid[i][col]){
            return false;
        }
    }

    //check if the upper left diagonal is safe
    for(int i=row,j=col;i>=0 && j>=0;i--,j--){
        if(Grid[i][j]){
            return false;
        }
    }

    //check if the upper right diagonal is safe
    for(int i=row, j=col;i>=0 && j<n; i--,j++){
        if(Grid[i][j]){
            return false;
        }
    }

    return true;
}

void solve(vector<vector<int>> &Grid, int n, int row){
    //print_grid(Grid);
    //we have solved each row so we can return true
    if(row==n){
        print_grid(Grid);
        cout<<endl;
    }
    else{
        for(int col=0;col<n;col++){
            //if a queen can be placed at the current row and column
            if(is_safe(Grid,n,row,col)){
                //place the queen at this position
                Grid[row][col]=1;
                /* check if placing the queen here can lead to a solution and keep finding the solutions
                don't stop after finding a solution.
                */
                solve(Grid, n, row+1);
            
                //could not solve the Grid by placing the queen at the current position so backtrack
                Grid[row][col]=0;
            }
        }
     
    }
}


void print_grid(vector<vector<int>> &Grid){
    for(auto x:Grid){
        for(auto y:x){
            cout<<y<<" ";
        }
        cout<<endl;
    }
}


