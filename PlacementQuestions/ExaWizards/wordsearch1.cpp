#include<bits/stdc++.h>

using namespace std;

bool exist(vector<vector<char>>& board, string word);
bool helper(vector<vector<char>> &board,string &word, int curr_idx, int x, int y,vector<int> &dir_x,vector<int> &dir_y,
vector<vector<int>> &visited);

int main(int argc, char const *argv[])
{
    /* code */
    string word="";

    vector<vector<char>> board ={{'A','B','C','E'},
                                {'S','F','C','S'},
                                {'A','D','E','E'}};

    cin>>word;

    cout<<exist(board,word)<<endl;

    return 0;
}


bool exist(vector<vector<char>>& board, string word){
    int m=board.size();
    int n=board[0].size();

    /* Below condition is for the following test case.
        [["a"]]
        "a"

        ! Written a clean solution on leetcode.
    
    */

    if(word.size()==1&& m==1 && n==1){
        if(word[0]==board[0][0]){
            return true;
        }
        else{
            return false;
        }
    }

    vector<int> dir_x{0,0,-1,1};
    vector<int> dir_y{1,-1,0,0};

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(helper(board,word,0,i,j,dir_x,dir_y)){
                return true;
            }
        }
    }

    return false;
}



bool helper(vector<vector<char>> &board,string &word, int curr_idx, int x, int y,vector<int> &dir_x,vector<int> &dir_y){
    
    if(curr_idx==word.size()){
        return true;
    }
  
    if(board[x][y]!=word[curr_idx]){
      return false;
    }
  
    // The same cell can't be used more than once so change its content
    board[x][y]='*';

    for(int i=0;i<4;i++){
        int new_x=x+dir_x[i];
        int new_y= y+dir_y[i];
        if(min(new_x,new_y)>=0 && new_x<board.size() && new_y<board[0].size()){
           if(helper(board,word,curr_idx+1,new_x,new_y,dir_x,dir_y)){
             return true;
           }     
        }
    }
  
    board[x][y]= word[curr_idx];
  
    return false;
}
