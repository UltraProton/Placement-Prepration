#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

void cut_rod(int n, vector<int> &prices, vector<int> &solution, vector<int> &table);
void get_solution(int n, vector<int> &solution);

int main(int argc, char const *argv[])
{
    vector<int> prices{0,1,5,8,9,10,17,17,20,24,30};
    vector<int> table(20,-1);
    vector<int> solution(20,0);

    cut_rod(10,prices,solution, table);
    
    cout<<endl;

    for(auto x:solution){
        cout<<x<<" ";
    }
    cout<<endl;
    get_solution(9,solution);

    return 0;
}

void cut_rod(int n, vector<int> &prices, vector<int> &solution,  vector<int> &table){
   
    // * we can't make a cut at if the length of rod is 0 
    table[0]=0;

    int q=INT_MIN;
    int s=0;
    // * for each length upto n
    for(int i=1;i<=n;i++){
        q=INT_MIN;
        // * if we make a cut at jth position 
        for(int j=1;j<=i;j++){
            // *  The resulting price will be price[j] + prices[i-j](remaining rod price)
            // * can we get a better price ?
            if(q<prices[i-j]+prices[j]){
                q=prices[i-j]+prices[j];
                s=j; // * save the solution
            }
        }

        table[i]=q;
        solution[i]=s;
    }
}


void get_solution(int n, vector<int> &solution){
    if(n==0){
        return;
    }

    int i=n;
    while(i>0){
        cout<<solution[i]<<" ";
        i=i-solution[i];
    }
}