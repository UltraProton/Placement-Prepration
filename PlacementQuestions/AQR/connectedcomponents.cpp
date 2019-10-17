//The edges are coming from input like queries

#include<bits/stdc++.h>

using namespace std;

class disjoint_set{
    public:
    int n_set;
    vector<int> parent;
    vector<int> size;
    disjoint_set(int n_set);
    void union_size(int u, int v);
    int find(int u);
    void make_set(int u);

};


int main(int argc, char const *argv[])
{

    vector<vector<int>> edges;
    disjoint_set dj(100);

    vector<int> made_set(100,0);

    string edge="";

    int n_edge=0;
    cin>>n_edge;

    int u=0;
    int v=0;

    int max_size_component=INT_MIN;

    for(int i=0;i<n_edge;i++){
        cin>>u>>v;
        if(!made_set[u]){
            dj.make_set(u);
            made_set[u]=1;
        }

        if(!made_set[v]){
            dj.make_set(v);
            made_set[v]=1;
        }

        dj.union_size(u,v);

        int u_size= dj.size[dj.parent[u]];
        int v_size= dj.size[dj.parent[v]];

        max_size_component= max(max_size_component, max(u_size,v_size));

        cout<<max_size_component<<endl;
        
    }

    // for(int i=1;i<=4;i++){
    //     cout<<dj.size[i]<<endl;
    // }

    return 0;
}

disjoint_set :: disjoint_set(int n_set){
    parent= vector<int>(n_set,-1);
    size= vector<int>(n_set,1);
}

void disjoint_set :: make_set(int u){
    parent[u]=u;
    size[u]=1;
}

int disjoint_set :: find(int u){
    if(parent[u]==u){
        return u;
    }

    parent[u]= find(parent[u]);
    return parent[u];
}

void disjoint_set :: union_size(int u ,int v){
    int p_u= find(u);
    int p_v= find(v);

    if(p_u==p_v){
        return;
    }

    if(size[p_u]>=size[p_v]){
        parent[p_v]=p_u;
        size[p_u]+=size[p_v];
    }
    else{
        parent[p_u]= p_v;
        size[p_v]+=size[p_u];
    }
}

