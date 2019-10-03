/* 

Here the representative of the set is the node whose parent in NULL. We can also have the strategy where the representative
of the set is the one whose parent is the node itself.

But its better to have the representative of a set pointing to itself. So here we will need another function MAKESET() which will
will make each node point to itself.

 */

#include<bits/stdc++.h>

using namespace std;

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
    void MAKESET(Node *n1);
    void UNION2(Node *n1, Node *n2);
    Node *FIND2(Node *n1);

};


int main(int argc, char const *argv[])
{
    disjoint_set obj;
    
    Node **nodes= new Node*[15];

    for(int i=1;i<=10;i++){
        nodes[i]= new Node(i);
        obj.MAKESET(nodes[i]);
        //cout<<nodes[i]->rank<<" ";
    }
    
    obj.UNION2(nodes[1],nodes[2]);
    obj.UNION2(nodes[2],nodes[3]);
    obj.UNION2(nodes[4],nodes[5]);
    obj.UNION2(nodes[6],nodes[7]);
    obj.UNION2(nodes[5],nodes[6]);
    obj.FIND2(nodes[7]);
    obj.UNION2(nodes[3],nodes[7]);

    //cout<<nodes[4]->rank<<endl;
    //cout<<nodes[2]->rank<<endl;
    //cout<<nodes[1]->parent->val<<endl;
    
    for(int i=1;i<=7;i++){
        if(nodes[i]->parent){
            cout<<nodes[i]->parent->val<<" ";
        }
        
        //cout<<nodes[i]->rank<<" ";
    }

  

    return 0;
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

void disjoint_set :: MAKESET(Node *n1){
    n1->parent=n1;
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

    if(p1->rank >=p2->rank){
        if(p1->rank==p2->rank){
            //if the w nodes are of the same rank then rank of the decided parent must be 1 more than its previous rank
            p1->rank++;
        }
        p2->parent= p1;
    }
    else{
        p1->parent= p2;
    }
}



