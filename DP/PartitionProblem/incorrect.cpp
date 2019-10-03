
/* 
? Failed test case: 
8
478 757 314 471 729 100 459 618

*/ 

#include<bits/stdc++.h>

using namespace std;

bool partition_possible(vector<int> &S, int l, int r);
int sum(vector<int> &S, int l, int r);

int main(int argc, char const *argv[])
{
    vector<int> S{1, 5, 3};
    
    cout<<partition_possible(S,0,S.size()-1)<<endl;

    return 0;
}

bool partition_possible(vector<int> &S, int l, int r){
    if(l>=r){
        return false;
    }

    else{
        int set_sum= sum(S,l,r);

        if(set_sum%2){
            return false;
        }
        else{

            for(int i=l;i<r;i++){
                bool ans= partition_possible(S,l,i) || partition_possible(S,i+1,r);
                if(ans){
                    return ans;
                }
            }
        }
    }
}



int sum(vector<int> &S){
    int ans=0;
    for(auto x:S){
        ans+=x;
    }

    return ans;
}
