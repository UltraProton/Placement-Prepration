/* 
See the recursive implementation and compare this with that to get the better understanding.


 */
#include<bits/stdc++.h>

using namespace std;

int coin_change(vector<int> &S, int target);

void print_table(vector<vector<int>> &table);

int main(int argc, char const *argv[])
{
      /* code */
    int t=0;
    int m=0;
    vector<int> S;
    int x=0;
    int target=0;
    int n_change=0;
    cin>>t;

    while(t>0)
    {   
        n_change=0;
        cin>>m;
        while(m>0){
            cin>>x;
            S.emplace_back(x);
            m--;
        }

        cin>>target;
 
        cout<<coin_change(S,target)<<endl;
        

        S.clear();

        t--;
    }

    return 0;
}

int coin_change(vector<int> &S, int target){
    int m=S.size();
    vector<vector<int>> table(m+1,vector<int>(target+2,0));

    for(int i=0;i<m;i++){
        for(int j=0;j<=target;j++){
            if(j==0){
                table[i][j]=1;
                continue;
            }
            
            if(i-1>=0){
                table[i][j]+= table[i-1][j];
            }
            
            if(j-S[i]>=0){
                table[i][j]+= table[i][j-S[i]];
            }
        }
    }

    //print_table(table);

    return table[m-1][target];
}

void print_table(vector<vector<int>> &table){
    for(auto vec:table){
        for(auto ele:vec){
            cout<<ele<<"    ";
        }
        cout<<endl;
    }
}







