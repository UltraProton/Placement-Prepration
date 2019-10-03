/* 
Here the graph will be represented by set of edges.  

*/

#include<bits/stdc++.h>

using namespace std;

class edge{
    private:
    int u;
    int v;
    int w;

    public:
    edge();
    edge(int u,int v, int w);
    void print_edge(edge &e);
    int get_u();
    int get_v();
    int get_w();
};

class Graph{
    private:
    int V;
    int E;
    vector<edge> *edge_list;
    
    public:
    Graph(); 
    Graph(int v,int e);
    void insert_edge(edge e);
    void print_edges();
    int n_vertices();
    int n_edges();
    vector<edge> * Edges();
    ~Graph();

};

class Node{
    public : 
    int val;
    int rank;
    Node *parent;
    Node(int x);
};

class disjoint_set{

    public: 
    void UNION1(Node *n1, Node *n2);
    Node *FIND1(Node *n1);
    //Following functions use self link strategy
    Node * MAKESET(Node *n1);
    void UNION2(Node *n1, Node *n2);
    Node *FIND2(Node *n1);

};


bool cycle(Graph &g);

int main(int argc, char const *argv[])
{

    Graph g(5,5);
    /* Create some edges */
    g.insert_edge(edge(1,2,3));
    g.insert_edge(edge(2,3,5));
    g.insert_edge(edge(3,4,7));
    g.insert_edge(edge(4,5,9));
    //g.insert_edge(edge(5,2,9));
    

    //for(auto x:)  
    //g.print_edges();

    cout<<cycle(g)<<endl;
    
    return 0;
}

bool cycle(Graph &g){
    
    disjoint_set obj;
    Node *temp;
    vector<edge> *edge_list= g.Edges();
    Node *n1,*n2;

    Node *vertices[10];

    for(int i=1;i<=g.n_vertices();i++){
        vertices[i]= obj.MAKESET(new Node(i));
    }
    
    for(auto x:(*edge_list)){
        n1= obj.FIND2(vertices[x.get_u()]);
        n2= obj.FIND2(vertices[x.get_v()]);
        //if the set of both the vertices of the edge is same then we got a cycle
        if(n1==n2){
            return true;
        }

        //put the 2 vertices of the edge in the same set
        obj.UNION2(n1,n2);
    }
    
    return false;
}

edge :: edge(){}

edge :: edge(int u, int v,int w){
    this->u=u;
    this->v=v;
    this->w=w;
}

void edge :: print_edge(edge &e){
    cout<<e.u<<" "<<e.v<<" "<<e.w<<endl;
}

int edge :: get_u(){
    return u;
}


int edge :: get_v(){
    return v;
}

int edge :: get_w(){
    return w;
}

Graph ::Graph(){}

Graph :: ~Graph(){
    //assert(edge_list);
    //delete [] operator is not definded for the vector of user defined types
    //delete [] edge_list;
}

Graph :: Graph(int v, int e){
    V=v;
    E=e;
    edge_list = new vector<edge>();
}

void Graph :: insert_edge(edge e){
    (*edge_list).emplace_back(e);
}

void Graph::print_edges(){
    for(auto x:(*edge_list)){
        x.print_edge(x);
    }
}

int Graph:: n_edges(){
    return E;
}


int Graph:: n_vertices(){
    return V;
}


vector<edge> * Graph:: Edges(){
    return edge_list;
}

Node::Node(int x){
    val=x;
    rank=0;
    parent=NULL;
}

/* This is FIND by compression.  */
Node * disjoint_set :: FIND1(Node *n){
    if(n->parent==NULL){
        return n;
    }
    n->parent= FIND1(n->parent);
    return n->parent;
}

/* This UNION by rank. */
void disjoint_set:: UNION1(Node *n1, Node *n2){
    Node *r1= FIND1(n1);
    Node *r2= FIND1(n2);

    if(r2->rank > r1->rank){
        r1->parent= r2;
    }
    else if(r1->rank > r2->rank){
        //cout<<'x'<<endl;
        r2->parent= r1;
    }
    else{
        //cout<<'x'<<endl;
        r2->parent= r1;
        r1->rank+=1;
    }
}

Node * disjoint_set :: MAKESET(Node *n1){
    n1->parent=n1;
    return n1;
}

Node * disjoint_set :: FIND2(Node *n1){
    if(n1->parent==n1){
        return n1;
    }

    n1->parent= FIND2(n1->parent);
    return n1->parent;
}


void disjoint_set :: UNION2(Node *n1, Node *n2){
    Node *p1=FIND2(n1);
    Node *p2= FIND2(n2);

    //n1->rank++;
    //p1->rank++;

    if(p1->rank >=p2->rank){
        if(p1->rank==p2->rank){
            p1->rank++;
        }
        p2->parent= p1;
    }
    else{
        p1->parent= p2;
    }
}




