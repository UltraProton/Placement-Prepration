#include<bits/stdc++.h>

using namespace std;

int mat_chain_mul(vector<int> &dimensions,int l, int r);
void print_solution(vector<vector<int>> &solution,int i, int j);
void print_vector(vector<vector<int>> &V);

int main(int argc, char const *argv[])
{
    
    vector<int> dimensions{30,35,15,5,10,20,25};
    int n=dimensions.size();
    
    vector<vector<int>> solution(n,vector<int>(n,0));
    
    cout<<endl;
    cout<<"min no of multiplications required: ";
    cout<<mat_chain_mul(dimensions,1,dimensions.size()-1)<<endl;

    //cout<<"solution:";
    //print_solution(solution,1,n-1);
    
    return 0;
}


int mat_chain_mul(vector<int> &dimensions, int l, int r){
    //we have only one matrix
    if(l==r){
        return 0;
    }
    else{
        int q=INT_MAX;
        //try different placements of parenthesis between first and last and count the cost of mulitiplications of 
        // each placement recursively and return the min cost 
        for(int k=l;k<r;k++){
            int first_half_ans= mat_chain_mul(dimensions,l,k);
            int second_half_ans= mat_chain_mul(dimensions,k+1,r);

            q= min(q, first_half_ans+second_half_ans+dimensions[l-1]*dimensions[k]*dimensions[r]);

        }

        return q;
    }
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