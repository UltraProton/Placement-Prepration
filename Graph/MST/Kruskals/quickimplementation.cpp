
/* This code is copy pasted from commutable islands problem on interviewbit. */



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

int kruskals(int A, vector<vector<int> > &B);

bool cmp(const vector<int> &x, const vector<int> &y);

int main(int argc, char const *argv[])
{
    //vector<vector<int>> B{{1, 2, 1},{2, 3, 2},{3, 4, 4},{1, 4, 3}};

    vector<vector<int>> B{ {1, 2, 1},
                           {2, 3, 4},
                           {1, 4, 3},
                           {4, 3, 2},
                           {1, 3, 10}  };

    cout<<kruskals(5,B)<<endl;
    
    return 0;
}


/* 
* Overall time complexity of Kruskal's algorithm: O(ElogV)
 
 */

int kruskals(int A, vector<vector<int>> &B) {
    disjoint_set ds(A+5);
    //set to store edges in the mst
    set<vector<int>> mst;
    
    int min_cost=0;

    // ! Sorting of edges is very crucial
    sort(B.begin(), B.end(), cmp); // ? O(ElogE)


    //for each vertex in the disjoint set call makeset // ? O(V)
    for(int i=0;i<ds.n_set;i++){
        ds.MAKESET(i);
    }

    for(auto x:B){ // ? O(2|E|)
        //find the set representative of u
        int p1= ds.FIND(x[0]);
        //find the set representative of v
        int p2= ds.FIND(x[1]);

        //if both have different set representatives
        if(p1!=p2){
            //we can add the cost of edge in the ans as it is safe to include the set in mst
            min_cost+=x[2];
            //then we can safely include this edge in the mst_set
            mst.insert(x);
            //union the 2 sets to indicate that we have included this edge as part of mst
            ds.UNION(p1,p2);
        }
    }

    return min_cost;
}

bool cmp(const vector<int> &x, const vector<int> &y){
    if(x[2] < y[2] ){
        return true;
    }
    else{
        return false;
    }
}

disjoint_set :: disjoint_set(int x){
    n_set=x;
    parent= vector<int>(n_set,-1); // parent of eah set element
    rank =vector<int>(n_set,0); // rank of each set element is 0
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


