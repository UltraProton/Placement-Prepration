#include<bits/stdc++.h>

#define UNASSIGNED 0;
#define N 4;

using namespace std;

bool sudoku_solve(vector<vector<char>> &board);
bool sudoku_solve_helper(vector<vector<char>> &board,int row,int col);
bool is_safe(vector<vector<char>> &board, int row, int col, int val);
bool is_subgrid_safe(vector<vector<char>> &board,int row,int col,int val);
bool is_row_safe(vector<vector<char>> &board,int row,int col,int val);
bool is_col_safe(vector<vector<char>> &board, int row, int col, int val);
void print(vector<vector<char>> &board);

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
vector<vector<char>> board(9,vector<char>(9,'.'));

/*vector<vector<char>> board={{'5','3','.','.','7','.','.','.','.'}, {'6','.','.','1','9','5','.','.','.'}, {'.','9','8','.','.','.','.','.','6','.'}, 
                            {"8...6...3"}, {"4..8.3..1"}, 
                            {"7...2...6"}, {".6....28."}, {"...419..5", "....8..79"}};
 */

    print(board);

    if(sudoku_solve(board)){
        print(board);
    }
    else{
        cout<<"No solution exists"<<endl;
    }
    
    return 0;

}

bool sudoku_solve(vector<vector<char>> &board){
    
    for(int row=0;row<9;row++){
        for(int col=0;col<9;col++){
            if(board[row][col]== '.'){
                for(char val='1';val<='9';val++){
                    if(is_safe(board,row,col,val)){
                        board[row][col]=val;
                        bool finished= sudoku_solve(board);
                        
                        if(finished==true){
                            return true;
                        }
                        
                        board[row][col]='.';
                    }
                }
                return false;
            }

        }
    }
    return true;
}
    

bool is_safe(vector<vector<char>> &board, int row , int col, int val){
    //check for the subgrid in which the element belongs
    // we need to reuse the set
    // check for the current row on the right side
    // check for the current column on the right side
    if(board[row][col]=='.' && is_row_safe(board,row,col,val) && is_col_safe(board,row, col,val) 
        && is_subgrid_safe(board,row-row%3,col-col%3,val)){
        return true;
    }
    else{
        return false;
    }
}

bool is_subgrid_safe(vector<vector<char>> &board,int row, int col, int val){
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(board[i+row][j+col]==val){
                    return false;
            }
        }
    }
    return true;
}

bool is_row_safe(vector<vector<char>> &board,int row, int col, int val){
    for(int i=0;i<9;i++){
        if(board[row][i]==val){
            return false;
        }
    }

    return true;
}

bool is_col_safe(vector<vector<char>> &board, int row, int col, int val){
    for(int i=0;i<9;i++){
        if(board[i][col]==val){
            return false;
        }
    }

    return true;
}


void print(vector<vector<char>> &board){
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
}