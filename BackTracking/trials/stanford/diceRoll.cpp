#include<bits/stdc++.h>

using namespace std;

void dice(int n_dice);
void dice_helper(int n_dice, vector<int> curr);
void print(vector<int> &);

int main(int argc, char const *argv[])
{
    /* code */
    dice(2);
    return 0;
}


void dice(int n_dice){
    vector<int> curr;
    dice_helper(n_dice,curr);
}

/* 

Here also the first parameter n_dice is signifying the no of dice left to be considered. Once the n_dice is 0 then there
are no dice to be rolled and we have the ans stored in our curr and we can print it.

 */


void dice_helper(int n_dice, vector<int> curr){
    if(n_dice==0){
        print(curr);
    }

    //else there are some dice left to roll
    else{
        //let's handle one dice 
        for(int i=1;i<=6;i++){  //for each value the dice could have 
            curr.emplace_back(i); // choose 
            dice_helper(n_dice-1, curr); // explore
            curr.pop_back(); // unchoose
        }
    }
}

void print(vector<int> &curr){
    for(auto x:curr){
        cout<<x<<" ";
    }
    cout<<endl;
}
