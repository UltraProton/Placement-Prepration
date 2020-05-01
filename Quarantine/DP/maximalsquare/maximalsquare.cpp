#include<bits/stdc++.h>

using namespace std;

int max_square(vector<vector<int>> &grid);
int max_square_dp(vector<vector<int>> &grid);

int main(){
    vector<vector<int>> grid{{1,1,1},{1,1,1},{1,1,1}};
    cout<<max_square(grid)<<endl;
    return 0;
}

int max_square(vector<vector<int>> &grid){
    int m=grid.size();
    int n=grid[0].size();
    int r=0,c=0,x=0,y=0;
    int mlen=0;
    //Here for each index in the grid if it is a 1 then keep expanding diagonally and check the column and row 
    //at that diagonal for 0's if no zero is found then keep expanding diagonal. If any index element in the 
    //column or row is 0 then we break because we no longer can find the index.  Remember that the diagonal of
    //a square is equal to its length.
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]==1){
                int sqlen=1; //Stores the length of the current square
                bool flag=1;
                //While the index
                while(i+sqlen<m && j+sqlen<n && flag==1){
                    for(int k=j;k<=j+sqlen;k++){
                        if(grid[i+sqlen][k]=='0'){
                            flag=0;
                            break;
                        }
                    }

                    for(int k=i;k<=i+sqlen;k++){
                        if(grid[k][j+sqlen]=='0'){
                            flag=0;
                            break;
                        }
                    }
                    //If the flag is 1 that means we didn't find any 0's in the square which means we can check for
                    //expanding it further
                    if(flag==1){
                        sqlen++;
                    }
                }
                //If we have come out of the loop then we have a sqlen(square length) which may be new ans
                mlen=max(mlen,sqlen);
            }
               
        }
    }

    return (mlen*mlen);
}

//To understand this equation fill the dp table yourself and get the idea.
/* Idea: dp[i][j] stores the max length of square with the 1 at grid[i-1][j-1] as the bottom right element. We are
taking the min because any 0 in the square can fail the maximal square length to be incremented. */
int max_square_dp(vector<vector<char>>& grid) {
        int m=grid.size();
        if(m==0){
            return 0;
        }
        int n=grid[0].size();

        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        int len=0;
        
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(grid[i-1][j-1]=='1'){
                    dp[i][j]= min(dp[i-1][j], min(dp[i][j-1],dp[i-1][j-1]))+1;
                    len=max(len,dp[i][j]);
                }
            }
        }
        
        return (len*len);
    
}