#include<bits/stdc++.h>

using namespace std;

int zero_one_knapsack(vector<int> &W, vector<int> &V, int w);
void print_table(vector<vector<int>> &table);

int main(int argc, char const *argv[])
{
    /* code */
    vector<int> V{1, 2, 3};  
    vector<int> W{1, 2, 2};  
    int w = 4; 


    /*  */

    cout<<zero_one_knapsack(W,V,w)<<endl;

    return 0;
}

int zero_one_knapsack(vector<int> &W, vector<int> &V, int w){
    int m=W.size();
    vector<vector<int>> table(m+1,vector<int>(w+1,0));

    for(int i=0;i<=m;i++){
        for(int j=0;j<=w;j++){
            if(i==0 || j==0){
                table[i][j]=0;
            }

            else{
                table[i][j]= max(table[i-1][j-1]+V[i], table[i-1][j]);
            }
        }
    }

    print_table(table);

    //* If we have m elements and w weight then the ans value is at the location table[m][w]
    return table[m][w];
}

void print_table(vector<vector<int>> &table){
    for(auto vec:table){
        for(auto ele:vec){
            cout<<ele<<" ";
        }
        cout<<endl;
    }
}