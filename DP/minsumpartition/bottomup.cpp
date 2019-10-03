#include<bits/stdc++.h>

using namespace std;

int ceil(int n, int x);
bool has_subset_sum(vector<int> &S, int target);
int min_sum_partition(vector<int> &S);

int main(int argc, char const *argv[])
{
    /* code */
    int n=0,t=0,x=0;
    vector<int> S;
    cin>>t;
    while(t>0){
        S.clear();
        cin>>n;
        while(n>0){
            cin>>x;
            S.emplace_back(x);
            n--;
        }

        //cout<<has_subset_sum(S,20)<<endl;
        cout<<min_sum_partition(S)<<endl;
        // char c='y';
        // int a=0;
        // while(c=='y'){
        //     cin>>a;
        //     cout<<has_subset_sum(S,a)<<endl;
        //     cout<<"enter: ";
        //     cin>>c;
        // }

        t--;
    }

    return 0;
}

int min_sum_partition(vector<int> &S){
    int s=0;
    for(auto x:S){
        s+=x;
    }

    int min_sum= 0;

    //cout<<target<<endl;
    //cout<<has_subset_sum(S,20)<<endl;

    int x=s/2;
    //cout<<x<<endl;

    for(int i=x;i>=0;i--){
        if(has_subset_sum(S,i)==true){
            //cout<<i<<endl;
            return (s-2*i);
        }
    }

    return -1;
}

bool has_subset_sum(vector<int> &S, int target_sum){
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
            //* Because we need idx-1 here so we should check for appropriate index
            if(idx-1 >=0){
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
