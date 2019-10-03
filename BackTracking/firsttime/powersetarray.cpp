
/*Implement the powerset of a set with duplicates allowed. [] */


#include<bits/stdc++.h>

using namespace std;

void powersetDFS(vector<int> &A, vector<int> &subset, int ind);
void powersetDFSWithBaseCase(vector<int> &A, vector<int> &subset,int ind);
void powersetClear(vector<int> &A, vector<int> &subset,int ind,vector<vector<int>> &);
void printset(vector<int> &arr);
void tab(int n);

int main(){
    vector<int> v{'a','b','c'};
    vector<int> subset;
    vector<vector<int>> ans;
    powersetDFS(v,subset,0);
    //powersetDFSWithBaseCase(v,subset,-1);
    //powersetClear(v,subset,0,ans);

    return 0;
}

/*In the array at each step we have 2 )choices to make include the element or exclude the element */

void powersetDFS(vector<int> &A, vector<int> &subset,int ind){
        tab(ind);
        cout<<"fun( "<<ind <<" )";
        printset(subset);
        cout<<endl;    
    //for each element in the set
    for(int i=ind;i<A.size();i++){
        //choose the element at the current index
        subset.push_back(A[i]);
        //recurse for the elements after the current index
        powersetDFS(A,subset,i+1);
        //remove the element triggers backtracking
        subset.pop_back();
    }

    return;

}


void powersetDFSWithBaseCase(vector<int> &A, vector<int> &subset,int ind){
    if(ind==A.size()){
        return;
    }
    tab(ind);
    cout<<"fun( "<<ind <<" )";
    printset(subset);
    cout<<endl; 
    //for each element in the set
    for(int i=ind+1;i<A.size();i++){
        //choose the element at the current index
        subset.push_back(A[i]);
        //explore
        powersetDFSWithBaseCase(A,subset,i);
        //backtrack...
        // Once all subsets beginning with 
        // initial "curr" are printed, remove 
        // last character to consider a different 
        // prefix of subsets. 
        //subset.erase(subset.end()-1);
        subset.pop_back();
    }

    return;

}
 


void powersetClear(vector<int> &A, vector<int> &subset,int ind,vector<vector<int>> &ans){
        tab(ind);
        cout<<"fun( "<<ind <<" )";
        printset(subset);

        if(ind==A.size()){
            ans.push_back(subset);
            return;        
        }

        //choose the element at the current index
        subset.push_back(A[ind]);
        //explore with the current element included
        powersetClear(A,subset,ind+1,ans);
        //remove the element at the current index        
        subset.pop_back();
        //explore with the element removed
        powersetClear(A,subset,ind+1,ans);
    }

void printset(vector<int> &subset){
    for(auto x:subset){
        cout<<char(x)<<" ";
    }
    cout<<endl;
} 

void tab(int n){
    for(int i=1;i<=n;i++){
        cout<<" ";
    }
}

/*O/p of Clear code:
fun( 0 )
 fun( 1 )a 
  fun( 2 )a b 
   fun( 3 )a b c 
   fun( 3 )a b 
  fun( 2 )a 
   fun( 3 )a c 
   fun( 3 )a 
 fun( 1 )
  fun( 2 )b 
   fun( 3 )b c 
   fun( 3 )b 
  fun( 2 )
   fun( 3 )c 
   fun( 3 )
   
    */