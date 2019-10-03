#include<bits/stdc++.h>

using namespace std;

class set_node{
    public:
    set_node *parent;
    int rank;
    int vertex;
    set_node(){}
    set_node(int v);
};

class disjoint_set{
    public:
    //list of nodes in the disjoint set
    vector<set_node *> node_list;
    //constructor
    disjoint_set();
    //make set function
    void MAKESET(int v);
    //function to find the set where to which v belongs to
    set_node* FIND(set_node *v);
    void UNION(int u, int v);
    ~disjoint_set();
};

class edge{
    public:
    int u;
    int v;
    int w;
    //edge(){}
    edge(int u, int v, int w);
};

class Graph{
    public:
    int V;
    vector<edge *> edge_list;
    Graph(int n_vertices);
    void print_edges();
    void add_edge(int u,int v, int wt);   
};



bool cmp(const edge *e1, const edge *e2);

void kruskals(Graph &G){
    set<edge *> mst;
    disjoint_set ds_obj;
    //make set of every vertex in the graph for operations in disjoint set
    for(int i=1;i<=G.V;i++){
        ds_obj.MAKESET(i);
    }
    
    //sort the edges in increasing order of weight
    sort(G.edge_list.begin(), G.edge_list.end(),cmp);

    for(auto edge : G.edge_list){
        set_node *a= ds_obj.FIND(ds_obj.node_list[edge->u]);
        set_node *b= ds_obj.FIND(ds_obj.node_list[edge->v]);

        if(a!=b){
            mst.emplace(edge);
            ds_obj.UNION(edge->u,edge->v);
        }
    }

    //print the set of edges in the mst

    for(auto edge: mst){
        cout<<char(edge->u)<<" "<<char(edge->v)<<" "<<edge->w<<endl;
    }
}

int main(int argc, char const *argv[])
{
    Graph G(150);

    G.add_edge('a','b',4);
    G.add_edge('a','h',8);
    G.add_edge('b','h',11);
    G.add_edge('b','c',8);
    G.add_edge('h','i',7);
    G.add_edge('h','g',1);
    G.add_edge('i','g',6);
    G.add_edge('i','c',2);
    G.add_edge('g','f',2);
    G.add_edge('f','c',4);
    G.add_edge('f','d',14);
    G.add_edge('d','c',7);
    G.add_edge('f','e',10);
    G.add_edge('e','d',9);

    
    
    //G.print_edges();


    kruskals(G);

    return 0;
}

bool cmp(const edge *e1, const edge *e2){
    
    return ((e1->w) < (e2->w));
}


set_node :: set_node(int v){
    parent=NULL;
    rank=0;
    vertex=v;
}


// constructor to initialize a list
disjoint_set :: disjoint_set(){
    //20 list of set_node pointers are given to list
    node_list= vector<set_node*>(150);
}



void disjoint_set :: MAKESET(int v){
    set_node * new_set= new set_node(v);
    new_set->parent=new_set;
    node_list[v]= new_set;
}

set_node* disjoint_set :: FIND(set_node *v){
    if(v->parent==v){
        return v;
    }

    else{
        v->parent= FIND(v->parent);
        return v->parent;
    }
}

void disjoint_set :: UNION(int u, int v){
    set_node *t1= FIND(node_list[u]);
    set_node *t2= FIND(node_list[v]);

    if(t1->rank>=t2->rank){
        if(t1->rank == t2->rank){
            t1->rank++;  
        }
        t2->parent=t1;
    }
        else{
            t1->parent=t2;
        }
} 



disjoint_set :: ~disjoint_set(){}

edge ::edge(int u, int v, int w){
    this->u=u;
    this->v=v;
    this->w=w;
}

void Graph :: add_edge(int u, int v, int wt){
    edge *new_edge= new edge(u,v,wt);
    edge_list.push_back(new_edge);    
}

Graph::Graph(int n_vertices){
    V=n_vertices;
}

void Graph :: print_edges(){
    for(auto x:edge_list){
        cout<<char(x->u)<<" "<<char(x->v)<<" "<<x->w<<endl;
    }
}
