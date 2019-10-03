#include<bits/stdc++.h>

using namespace std;


class disjoint_set{
    public:
    int n_set;
    vector<int> parent;
    vector<int> rank;

    disjoint_set(int n_set);
    void MAKESET(int u);
    void UNION(int u, int v);
    int FIND(int u);
};



int main(int argc, char const *argv[])
{
    disjoint_set obj(10);
    
    for(int i=0;i<=9;i++){
        obj.MAKESET(i);
        //cout<<nodes[i]->rank<<" ";
    }
    
    obj.UNION(1,2);
    obj.UNION(2,3);
    obj.UNION(4,5);
    obj.UNION(6,7);
    obj.UNION(5,6);
    obj.FIND(7);
    obj.UNION(3,7);

    //cout<<nodes[4]->rank<<endl;
    //cout<<nodes[2]->rank<<endl;
    //cout<<nodes[1]->parent->val<<endl;
    
    for(int i=1;i<=7;i++){
        cout<<obj.parent[i]<<" ";
        //cout<<nodes[i]->rank<<" ";
    }

    return 0;
}



// disjoint_set :: disjoint_set(int n_set){
//     this->n_set= n_set;
// }

disjoint_set :: disjoint_set(int x){
    n_set=x;
    parent= vector<int>(n_set,-1);
    rank =vector<int>(n_set,0);
}

void disjoint_set :: MAKESET(int u){
    parent[u]=u;
    rank[u]=0;
}

int disjoint_set :: FIND(int u){
    if(parent[u]==u){
        return u;
    }
    else{
        parent[u]= FIND(parent[u]);
        return parent[u];
    }
}
void disjoint_set :: UNION(int u, int v){
    int x=FIND(u);
    int y=FIND(v);

    if(rank[x]>=rank[y]){
        parent[y]=x;
        if(rank[x]==rank[y]){
            rank[x]++;
        }
    }
    else{
        parent[x]=y;
    }
}


