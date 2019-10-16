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

        // cin>>target;

        // cout<<subset_sum(S,target)<<endl;
        
        char c='y';
        int a=0;
        while(c=='y'){
            cin>>a;
            cout<<subset_sum(S,a)<<endl;
            cout<<"enter: ";
            cin>>c;
        }


        t--;
    }

    
    return 0;
}

bool subset_sum(vector<int> &S, int target_sum){
    int n=S.size();
    vector<vector<int>> table(n+1,vector<int>(target_sum+1,0));


    // for(int i=0;i<=n;i++){
    //     table[i][0]=1;
    // }

    // //* If no of elements are 0 and target sum is greater than 0 then the solution is false
    // for(int i=1;i<=target_sum;i++){
    //     table[0][i]=0;
    // }

    for(int idx=0;idx<=S.size();idx++){
        for(int j=0;j<=target_sum;j++){
            if(j==0){
                table[idx][j]=1;
                continue;
            }

            if(idx==0 && j!=0){ //* j!=0 is required in case if no of elements are zero and the target sum is zero then we have an
                                //* empty set as the ans and we don't want to put zero in table[0][0]
                table[idx][j]= 0;
                continue;//* Remember idx-1 in the below cases will give segmentation fault if we don't continue from here.
            }

            //* Because we need idx-1 here so we should check for appropriate index
            if(S[idx-1]>j){
                table[idx][j]= table[idx][j] ||  table[idx-1][j];
            }
 
            if(j-S[idx-1]>=0){
                table[idx][j]= table[idx][j] || table[idx-1][j-S[idx-1]];
            }
        }
    }
    
    print_table(table);

    int ans= table[S.size()][target_sum];

    table.clear();

    return ans;
}

void print_table(vector<vector<int>> &table){
    for(auto vec:table){
        for(auto ele:vec){
            cout<<ele<<"    ";
        }
        cout<<endl;
    }
}

