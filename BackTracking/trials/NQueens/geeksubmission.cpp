#include<bits/stdc++.h>

using namespace std;

bool is_safe(vector<vector<int>> &Grid, int n, int row, int col);
void solve(vector<vector<int>> &Grid, int n, int col);
//void make_solution(vector<vector<int>> &Grid);
void print_grid(vector<vector<int>> &Grid);

int main(int argc, char const *argv[])
{
    int t=0,n=0;
    cin>>t;

    while(t>0){
        cin>>n;
        if(n==2 || n==3){
            cout<<-1;
        }
        else{
            vector<vector<int>> Grid(n,vector<int>(n,0));
            solve(Grid, n,0);
        }
        
        cout<<endl;
        t--;
    }
    

    //print_grid(Grid);

    return 0;
}


bool is_safe(vector<vector<int>> &Grid, int n, int row, int col){
    //check if the row is safe
    for(int i=col;i>=0;i--){
        if(Grid[row][i]){
            return false;
        }
    }

    //check if the upper left diagonal is safe
    for(int i=row,j=col;i>=0 && j>=0;i--,j--){
        if(Grid[i][j]){
            return false;
        }
    }

    //check if the lower left diagonal is safe
    for(int i=row, j=col;i<n && j>=0; i++,j--){
        if(Grid[i][j]){
            return false;
        }
    }

    return true;
}

void solve(vector<vector<int>> &Grid, int n, int col){
    //print_grid(Grid);
    //we have solved each row so we can return true
    if(col==n){
        cout<<"[";
        for(int col=0;col<n;col++){
            for(int row=0;row<n;row++){
                if(Grid[row][col]){
                    cout<<row+1<<" ";
                }
            }
        }
        cout<<"]";
        cout<<endl;
    }
    else{
        for(int row=0;row<n;row++){
            //if a queen can be placed at the current row and column
            if(is_safe(Grid,n,row,col)){
                //place the queen at this position
                Grid[row][col]=1;
                /* check if placing the queen here can lead to a solution and keep finding the solutions
                don't stop after finding a solution.
                */
                solve(Grid, n, col+1);
            
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



