/* 
 ! In the bottom up way we should go from left to right only to fill the table which is why we had to think of this
 ! strategy here.

 ! Time Complexity: O(n*target)

 ? We can compare this problem with the coin change problem with slight modification.

 */




#include<bits/stdc++.h>

using namespace std;

bool subset_sum(vector<int> &S, int target_sum);
void print_table(vector<vector<int>> &table);

int main(int argc, char const *argv[])
{
    
    vector<int> S;

    int t=0;
    int n=0;
    int x=0;
    int target=0;
    cin>>t;
    while(t>0){
        S.clear();
        cin>>n;
        while(n>0){
            cin>>x;
            S.emplace_back(x);
            n--;
        }

        cin>>target;

        cout<<subset_sum(S,target)<<endl;
        
        // char c='y';
        // int a=0;
        // while(c=='y'){
        //     cin>>a;
        //     cout<<subset_sum(S,a)<<endl;
        //     cout<<"enter: ";
        //     cin>>c;
        // }


        t--;
    }

    
    return 0;
}

bool subset_sum(vector<int> &S, int target_sum){
    int n=S.size();
    vector<vector<int>> table(n+1,vector<int>(target_sum+1,0));

    for(int i=0;i<=n;i++){
        table[i][0]=1;
    }

    //* If no of elements are 0 and target sum is greater than 0 then the solution is false
    for(int i=1;i<=target_sum;i++){
        table[0][i]=0;
    }

    for(int idx=1;idx<=S.size();idx++){
        for(int j=1;j<=target_sum;j++){
            if(j < S[idx-1]){ //? This if condition is equal to if(j-S[idx-1] < 0) 
            //? Note we don't need to check for idx-1 being valid or not because we are starting from idx=1 and the worst 
            //? idx-1 can be 0 which is a valid index
                table[idx][j]= table[idx][j] ||  table[idx-1][j];
            }
 
            if(j-S[idx-1]>=0 && idx-1>=0){
                table[idx][j]= table[idx][j] || table[idx-1][j-S[idx-1]];
            }
        }
    }
    
    //print_table(table);
    return table[S.size()][target_sum];
}

void print_table(vector<vector<int>> &table){
    for(auto vec:table){
        for(auto ele:vec){
            cout<<ele<<"    ";
        }
        cout<<endl;
    }
}

