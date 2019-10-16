#include<bits/stdc++.h>

using namespace std;

int mat_chain_mul(vector<int> &dimensions,vector<vector<int>> &solution);
void print_solution(vector<vector<int>> &solution,int i, int j);
void print_vector(vector<vector<int>> &V);

int main(int argc, char const *argv[])
{
    
    vector<int> dimensions{30,35,15,5,10,20,25};
    int n=dimensions.size();
    
    vector<vector<int>> solution(n,vector<int>(n,0));
    
    cout<<endl;
    cout<<"min no of multiplications required: ";
    cout<<mat_chain_mul(dimensions,solution)<<endl;

    cout<<"solution:";
    print_solution(solution,1,n-1);
    
    return 0;
}


int mat_chain_mul(vector<int> &dimensions, vector<vector<int>> &solution){
    int n=dimensions.size();
    vector<vector<int>> table(n,vector<int>(n,0));
    
    int j=0;
    int q=0;
    // ! See till where the indices go to quickly implemen this solution
    for(int l=2;l<n;l++){//for each length of chain of matrix starting from minimum 2 matrices in chain
        for(int i=1;i<n-l+1; i++){
            j=i+l-1;
            table[i][j]=INT_MAX;
            //for each 'k' where cut can be made between the chain
            for(int k=i;k<j;k++){
                //find the cost of multiplication with parentheis at position k
                q=table[i][k] + table[k+1][j]+ dimensions[i-1]*dimensions[k]*dimensions[j];
                //if this parenthization produces the min cost then this is the possible parenthization
                if(q<table[i][j]){
                    table[i][j]=q;
                    //we can have parenthization at position k between matrices in the chain from i to j
                    solution[i][j]=k; // lower diagonal of the table is unused so we can optimize this code by storing
                                      // this information in lower diagonal of the matrix see the space optimized solution                
                }
            }
        }
    }

    cout<<endl;
    print_vector(table);

    return table[1][n-1];
}

void print_solution(vector<vector<int>> &solution,int i, int j){
    if(i==j){
        cout<<'A'<<i;
    }
    else{
        cout<<"(";
        print_solution(solution, i,solution[i][j]);
        print_solution(solution,solution[i][j]+1,j);
        cout<<')';
    }
}

void print_vector(vector<vector<int>> &V){
    for(auto x:V){
        for(auto y:x){
            cout<<y<<"    ";
        }
        cout<<endl;
    }
}