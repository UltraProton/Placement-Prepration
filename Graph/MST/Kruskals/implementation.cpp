#include<bits/stdc++.h>

using namespace std;

struct edge{
    int u;
    int v;
    int w;

    edge(int u,int v, int wt): u(u),v(v),w(wt){}
};

struct set_node{
    set_node *parent;
    int rank;
    int vertex;
    //parameterized constructor
    set_node(int v): parent(NULL), rank(0), vertex(v){}
};


class Graph{
    public:
    int V;
    vector<edge *> edge_list;
    Graph(int n_vertices);
    void print_edges();
    void add_edge(int u,int v, int wt);   
};



void MAKESET(int v,vector<set_node *> &node_list);
set_node* FIND(set_node *v);
void UNION(int u, int v, vector<set_node*> &node_list);
bool cmp(const edge *e1, const edge *e2);
void kruskals(Graph &G, vector<set_node *> &node_list);

int main(int argc, char const *argv[])
{
    Graph G(5);

    G.add_edge(1,2,1);
    G.add_edge(2,3,2);
    G.add_edge(3,5,10);
    G.add_edge(3,4,7);
    G.add_edge(4,2,0);

    vector<set_node*> node_list(20);
    
    G.print_edges();
    

    cout<<"\n\n\n";

    kruskals(G,node_list);

    return 0;
}

 bool cmp(const edge *e1, const edge *e2){
    
    return ((e1->w) < (e2->w));
}


void MAKESET(int v,vector<set_node *> &node_list){
    set_node * new_set= new set_node(v);
    //make the parent of  new node point to itself
    //so that it becomes representative of the set 
    new_set->parent=new_set;
    node_list[v]= new_set;
}

set_node* FIND(set_node *v){
    if(v->parent==v){
        return v;
    }

    else{
        v->parent= FIND(v->parent);
        return v->parent;
    }
}

void UNION(int u, int v, vector<set_node*> &node_list){
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


void Graph :: add_edge(int u, int v, int wt){
    edge *new_edge= new edge(u,v,wt);
    edge_list.push_back(new_edge);    
}

Graph::Graph(int n_vertices){
    V=n_vertices;
}

void Graph :: print_edges(){
    for(auto x:edge_list){
        cout<<x->u<<" "<<x->v<<" "<<x->w<<endl;
    }
}



void kruskals(Graph &G, vector<set_node *> &node_list){
    vector<edge *> mst;
    //make set of every vertex in the graph for operations in disjoint set
    for(int i=1;i<=G.V;i++){
        MAKESET(i,node_list);
    }
    
    //sort the edges in increasing order of weight
    sort(G.edge_list.begin(), G.edge_list.end(),cmp);


    //for each edge in the edge list of graphs sorted by weight
    for(auto edge : G.edge_list){
        set_node *a= FIND(node_list[edge->u]);
        set_node *b= FIND(node_list[edge->v]);

        if(a!=b){
            mst.emplace_back(edge);
            UNION(edge->u,edge->v,node_list);
        }
    }

    //print the set of edges in the mst
    int min_cost=0;
    for(auto edge: mst){
        min_cost+=edge->w;
        cout<<edge->u<<" "<<edge->v<<" "<<edge->w<<endl;
    }
}

