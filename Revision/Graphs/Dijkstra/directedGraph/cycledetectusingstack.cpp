#include<bits/stdc++.h>

using namespace std;

bool dfs_util(vector<vector<int>> &G, int src, vector<int> &visited, vector<int> &instack);

int main(int argc, char const *argv[])
{
    /* code */

    return 0;
}

bool dfs_util(vector<vector<int>> &G, int src, vector<int> &visited, vector<int> &instack){
    visited[src]=1;
    instack[src]=1;

    for(auto v: G[src]){
        //if the adjacent vertex is not yet explored then find whether we can get a cycle from this vertex
        if(!visited[v]){
            //if we find a cycle then return true;;
            if(dfs_util(G,v,visited,instack)){
                return true;
            }
        }

        //If the vertex is already visited and its still in the stack then we have got a backward edge to this 
        // vertex from some other vertex
        else if(instack[v]){
            return true;
        }
    }

    //We couldn't find the cycle starting from the source and we are done exploring all the adjacent vertices
    //of the source which means src is finished or turned black or we can remove src from the stack 
    instack[src]=0;
    return false;
}