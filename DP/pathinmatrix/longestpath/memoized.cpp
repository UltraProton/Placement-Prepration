/* 

https://www.geeksforgeeks.org/find-the-longest-path-in-a-matrix-with-given-constraints/

 */

#include<bits/stdc++.h>

using namespace std;

int path_in_matrix(vector<vector<int>> &mat);
int path_in_matrix_helper(vector<vector<int>> &mat, vector<vector<int>> &table,int i, int j, int n);

int main(int argc, char const *argv[])
{
    /* code */

    vector<vector<int>> mat{{1, 2, 9},{5, 3, 8},{4, 6, 7}};
    cout<<path_in_matrix(mat)<<endl;

    return 0;
}

int path_in_matrix(vector<vector<int>> &mat){
    int n=mat.size();
    //cout<<mat.size()<<endl;
    
    vector<vector<int>> table(n,vector<int>(n,-1));

    int result=1; //* Longest path with one element will be of length 1

    //* Find longest path from each cell
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(table[i][j]==-1){//* If the path is not already computed then compute it
                table[i][j]= path_in_matrix_helper(mat,table,i,j,n);
            }

            result= max(result, table[i][j]);
        }
    }

    return result;
}

//! Time complexity :  O(n^2) it may look more but notice that each value in the table is computed only once


int path_in_matrix_helper(vector<vector<int>> &mat, vector<vector<int>> &table, int i, int j, int n){
    
    //cout<<'x'<<endl;
    if(i<0 || j< 0 || i>=n || j>=n){
        return 0;
    }

    int l=0,r=0,u=0,d=0;

    if(table[i][j]!=-1){
        return table[i][j];
    }

    //* explore one step left
    if(j>0 && mat[i][j-1]==mat[i][j]+1){
        l= 1+ path_in_matrix_helper(mat,table,i,j-1,n);
    }

    //* explore one step right 
    if(j<n-1 && mat[i][j+1]== mat[i][j]+1){
        r= 1+ path_in_matrix_helper(mat, table, i,j+1,n);
    }

    //* explore one step up
    if(i>0 && mat[i-1][j]==mat[i][j]+1){
        u= 1+ path_in_matrix_helper(mat,table, i-1,j,n);
    }

    if(i<n-1 && mat[i+1][j]==mat[i][j]+1){
        d= 1+ path_in_matrix_helper(mat, table, i+1, j, n);
    }

    //* take the max of 4 values if none of the 4 values are greater than 1 then for this cell the current element is the only
    //* element in the longest path from this cell
    table[i][j]= max(l,max(r,max(u,max(d,1))));

    return table[i][j];

}