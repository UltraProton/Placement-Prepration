#include<bits/stdc++.h>

using namespace std;

//* Here we are going from [0,0] to [n-1,n-1]
int path_in_matrix1(vector<vector<int>> &mat,int i, int j, int n, int m);
int path_in_matrix2(vector<vector<int>> &mat,int m, int n,vector<vector<int>> &memo,int &path_possible);

int main(int argc, char const *argv[])
{
    vector<vector<int>> mat;
    vector<vector<int>> table;
    int t=0, n=0, n1=0,x=0;
    int i=0,j=0;
    vector<vector<int>> memo;

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

        //cout<<path_in_matrix(mat,0,0,n,n)<<endl;
        memo= vector<vector<int>>(n+1,vector<int>(n+1,-1));
        
        int path_possible=true;

        int first_traversal= path_in_matrix2(mat,n-1,n-1,memo,path_possible);
        
        cout<<path_possible<<endl;
        cout<<first_traversal<<endl;
        for(auto vec: mat){
            for(auto ele :vec){
                cout<<ele<<" ";
            }
            cout<<endl;
        }

        memo= vector<vector<int>>(n+1,vector<int>(n+1,-1));

        int second_traversal= path_in_matrix2(mat,n-1,n-1,memo,path_possible);

        if(path_possible){
            cout<<first_traversal+second_traversal<<endl;
        }

        else{
            cout<<"Path is not possible"<<endl;
        }

        t--;
    }
    
    return 0;
}

//* To reach [m][n] from [0][0] we can take reverse process also say we are at [m][n] then we can come to this position from 3 sides
//* [m-1][n], [m][n-1], [m-1][n-1] and we want min of these 3 choices

int path_in_matrix2(vector<vector<int>> &mat, int i, int j,vector<vector<int>> &memo, int &path_possible){
    //* We have gone outside the matrix to which is unacceptable so to reach a position outside of matrix is INFINITY
    if(i<0 || j <0){
        return INT_MIN; //* Pay attention we are minimizing the cost and this thing will always be avoided in our choice
    }

    if(memo[i][j]!=-1){
        return memo[i][j];
    }

    //* When we reach the destination in reverse order we should take the cost at that position
    else if(i==0 && j==0){
        return mat[i][j];
    }

    //* We have not yet reached the destination so we should make choices and also include the cost at the present cell
    else{
        
        if(i>0  && j>0 && mat[i-1][j]==-1 && mat[i][j-1]==-1 ){
            path_possible=false;
        }
        
        int x=path_in_matrix2(mat,i-1,j,memo,path_possible);
        int y=path_in_matrix2(mat,i,j-1,memo,path_possible); 
        
        if(x>y){
            
        }
        if(mat[i][j]==1){
            mat[i][j]=0;
        }

        return memo[i][j];
    }
}
