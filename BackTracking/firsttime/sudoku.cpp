#include<bits/stdc++.h>

#define UNASSIGNED 0;
#define N 4;

using namespace std;

bool sudoku_solve(vector<vector<int>> &board);
bool sudoku_solve_helper(vector<vector<int>> &board,int row,int col);
bool is_safe(vector<vector<int>> &board, int row, int col, int val);
bool is_subgrid_safe(vector<vector<int>> &board,int row,int col,int val);
bool is_row_safe(vector<vector<int>> &board,int row,int col,int val);
bool is_col_safe(vector<vector<int>> &board, int row, int col, int val);
void print(vector<vector<int>> &board);

int main(){
    /*vector<vector<int>> board{ 
                        { 0, 0, 0, 0,0,0,0,0,0}, 
                        { 0, 0, 0, 0,0,0,0,0,0}, 
                        { 0, 0, 0, 0,0,0,0,0,0}, 
                        { 0, 0, 0, 0,0,0,0,0,0},
                        { 0, 0, 0, 0,0,0,0,0,0},
                        { 0, 0, 0, 0,0,0,0,0,0},
                        { 0, 0, 0, 0,0,0,0,0,0},
                        { 0, 0, 0, 0,0,0,0,0,0},
                        { 0, 0, 0, 0,0,0,0,0,0} }; 
 */
vector<vector<int>> board(4,vector<int>(4,0));

    print(board);

    if(sudoku_solve(board)){
        print(board);
    }
    else{
        cout<<"No solution exists"<<endl;
    }
    
    return 0;

}

bool sudoku_solve(vector<vector<int>> &board){
    
    for(int row=0;row<4;row++){
        for(int col=0;col<4;col++){
            if(board[row][col]== 0){
                for(int val=1;val<=9;val++){
                    if(is_safe(board,row,col,val)){
                        board[row][col]=val;
                        bool finished= sudoku_solve(board);
                        
                        if(finished==true){
                            return true;
                        }
                        
                        board[row][col]=UNASSIGNED;
                    }
                }
                return false;
            }

        }
    }
    return true;
}
    

bool is_safe(vector<vector<int>> &board, int row , int col, int val){
    //check for the subgrid in which the element belongs
    // we need to reuse the set
    // check for the current row on the right side
    // check for the current column on the right side
    if(board[row][col]==0 && is_row_safe(board,row,col,val) && is_col_safe(board,row, col,val) 
        && is_subgrid_safe(board,row-row%2,col-col%2,val)){
        return true;
    }
    else{
        return false;
    }
}

bool is_subgrid_safe(vector<vector<int>> &board,int row, int col, int val){
        for(int i=0;i<2;i++){
            for(int j=0;j<2;j++){
                if(board[i+row][j+col]==val){
                    return false;
            }
        }
    }
    return true;
}

bool is_row_safe(vector<vector<int>> &board,int row, int col, int val){
    for(int i=0;i<4;i++){
        if(board[row][i]==val){
            return false;
        }
    }

    return true;
}

bool is_col_safe(vector<vector<int>> &board, int row, int col, int val){
    for(int i=0;i<4;i++){
        if(board[i][col]==val){
            return false;
        }
    }

    return true;
}


void print(vector<vector<int>> &board){
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
}