#include<bits/stdc++.h>

using namespace std;

bool detect_cycle(vector<int> *G,int n_vertices, vector<int> &color);
bool dfs_util(vector<int> *G, int src, vector<int> &color);
void add_edge(vector<int> *G,int src, int dest);

int main(int argc, char const *argv[])
{
    vector<int> *G= new vector<int> [2000];

    int n_vertices=0;

    vector<int> color(2000,0);
    
    int A = 2;
    
    vector<int> B{1, 2};
    vector<int> C{2, 1}; 
    

    for(int i=0;i<B.size();i++){
        add_edge(G,B[i],C[i]);
    }

    
    
    if(detect_cycle(G,A,color)==false){
        cout<<"yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }

    return 0;
}


bool detect_cycle(vector<int> *G, int n_vertices, vector<int> &color){
    for(int i=1;i<=n_vertices;i++){
        if(color[i]==0){
            if(dfs_util(G,i,color)){
                return true;
            }
        }
    }
    return false;
}

bool dfs_util(vector<int> *G, int src, vector<int> &color){
    color[src]=1;

    for(auto x:G[src]){
        if(color[x]==2){
            continue;
        }

        else if(color[x]==1){
            return true;
        }

        else{
            if(dfs_util(G,x,color)){
                return true;
            }
        }
    }

    color[src]=2;

    return false;
}

void add_edge(vector<int> *G, int src, int dest){
    G[src].push_back(dest);
}