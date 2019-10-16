#include<bits/stdc++.h>

using namespace std;

void dice_sum(int n_dice, int sum);
void dice_sum_helper_bad(int n_dice_left, vector<int>& , int sum);
void dice_sum_helper_good(int n_dice_left, vector<int>& , int sum_so_far, int target_sum);
void print(vector<int> &);
int vector_sum(vector<int> &v);
void tab(int n);

int main(int argc, char const *argv[])                
{
    dice_sum(5,28);

    return 0;
}


void dice_sum(int n_dice, int target_sum){
    vector<int> curr;
    dice_sum_helper_good(n_dice,curr,0,target_sum);
}


void dice_sum_helper_bad(int n_dice_left, vector<int> &curr, int sum){
    if(n_dice_left==0){
        print(curr);
    }

    else{
        for(int i=1;i<=6;i++){
            curr.emplace_back(i);
            dice_sum_helper_bad(n_dice_left-1,curr,sum);
            curr.pop_back();
        }
    }
}

void dice_sum_helper_good(int n_dice_left, vector<int> &curr, int sum_so_far, int target_sum){
    tab(curr.size());
    cout<<"fun( n= "<<n_dice_left<<" sumsofar= "<<sum_so_far<<" )"<<endl;
    if(n_dice_left==0){
        print(curr);        
    }

    else{
        for(int i=1;i<=6;i++){
            /* 
            
            So the below check ensures we don't explore bad paths.
            How?: if we include 'i' in the set then does the target sum lies between the least we can get by including 'i'
            and the largest we can get by including 'i'.
            E.g : diceSum(3,10)
            If we have chosen [6,4,_] then the least we can include is 1 which will exceed the target sum.
            Similarly if we have chosen[1,2,_] then the max we can get is 6 so we don't need to explore this 
            path as we are doomed to find any solution following it.             
            
             */
            if((sum_so_far + i+ (n_dice_left-1) <=target_sum) && //all the remaining dice have least possible value (1)
                (sum_so_far + i + (n_dice_left-1)*6 >=target_sum)) // all the remaining dice's have the largest possible value (6)                
                {

                curr.emplace_back(i);
                dice_sum_helper_good(n_dice_left-1,curr,sum_so_far+i, target_sum);
                curr.pop_back();
            }
        }
    }
}


void print(vector<int> &curr){
    for(auto x:curr){
        cout<<x<<" ";
    }
    cout<<endl;
}

                                  

int vector_sum(vector<int> &curr){
    int ans=0;
    for(auto x:curr){
        ans+=x;
    }

    return ans;
}


void tab(int n){
    for(int i=1;i<=n;i++){
        cout<<"    ";
    }
}