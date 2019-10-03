/* 
https://practice.geeksforgeeks.org/problems/path-in-matrix/0

*/

#include<bits/stdc++.h>

using namespace std;

int path_in_matrix(vector<vector<int>> &mat);
int path_in_matrix_helper(vector<vector<int>> &mat, vector<vector<int>> &table,int i, int j, int n);

int main(int argc, char const *argv[])
{
    vector<vector<int>> mat;
    vector<vector<int>> table;
    int t=0, n=0, n1=0,x=0;
    int i=0,j=0;
    cin>>t;
    while (t>0)
    {
        cin>>n;
        mat.clear();
        
        mat= vector<vector<int>>(n,vector<int>(n,0));
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin>>mat[i][j];
            }
        }

        cout<<path_in_matrix(mat)<<endl;
        
        t--;
    }
    
    return 0;
}

int path_in_matrix(vector<vector<int>> &mat){
    int n=mat.size();
    //cout<<mat.size()<<endl;
    
    vector<vector<int>> table(n,vector<int>(n,-1));//* Initial value of -1 in the memo indicates that the value corresponding
                                                   //* to the cell is not yet calculated

    int result=INT_MIN; //* Longest path with one element will be of length 1

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

    int a=0,b=0,c=0;

    if(table[i][j]!=-1){
        return table[i][j];
    }

    //* explore one step left
    if(i< n-1){
        a= mat[i][j] + path_in_matrix_helper(mat,table,i+1,j,n);
    }

    //* explore one step right 
    if(i < n-1 && j<n-1){
        b= mat[i][j] +  path_in_matrix_helper(mat, table, i+1,j+1,n);
    }

    if(i< n-1 && j>0){
        c= mat[i][j] +  path_in_matrix_helper(mat, table, i+1, j-1, n);
    }

    //* take the max of 4 values if none of the 4 values are greater than 1 then for this cell the current element is the only
    //* element in the longest path from this cell
    table[i][j]= max(a,max(b,max(c,mat[i][j])));

    return table[i][j];

}