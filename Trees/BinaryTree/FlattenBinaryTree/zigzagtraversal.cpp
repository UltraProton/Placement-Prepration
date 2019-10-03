#include<bits/stdc++.h>

using namespace std;

typedef struct node{
    int val;
    struct node *left;
    struct node *right;
    //constructor in side structure    
    node (int x): val(x),left(NULL),right(NULL){}

}Node;

void zigzag_traversal(Node *root); 
void zigzag_traversal_best(Node *root);
void level_order_traversal(Node *root);
void print_level(Node *root, int level);
void print_level_zigzag(Node *root, int level,int dir);
void insert_node(Node *&root, int val); //reference to pointer to node is given pay attention
void print_preorder(Node *root);
int height(Node *root);

int main(){
    Node *root= NULL;
    insert_node(root,1);
    //cout<<root->val<<endl;
    insert_node(root,2);
    insert_node(root,3);
    insert_node(root,4);
    insert_node(root,5);
    insert_node(root,6);
    insert_node(root,7);

    print_preorder(root);
    cout<<endl;
    level_order_traversal(root);

    cout<<endl;

    zigzag_traversal(root);
    cout<<endl;


    return 0;

}

void insert_node(Node *&root, int val){
    Node *temp= new Node(val);

    if(!root){
        root=temp;
        //cout<<root->val<<endl;
        return;
    }
    
    queue<Node *> Q;
    Q.push(root);
    Node *curr=NULL;
    
    while(!Q.empty()){
        curr=Q.front();
        Q.pop();
        //if current left is NULL insert new node at current's left
        if(!curr->left){
            curr->left=temp;
            return;
        }
        
        else if(!curr->right){
            curr->right=temp;
            return;
        }

        //keep finding the empty place
        else
        {
            Q.push(curr->left);
            Q.push(curr->right);
        }
    
    }
}

void print_preorder(Node *root){
    if(!root){
        return;
    }
    else{
        cout<<root->val<<" ";
        print_preorder(root->left);
        print_preorder(root->right);
        
    }
}

void level_order_traversal(Node *root){
    int h=height(root);
    for(int d=1;d<=h;d++){
        print_level(root,d);
    }
}

void zigzag_traversal(Node *root){
    if(!root){
        return;
    }
    int h=height(root);
    for(int d=1;d<=h;d++){
        print_level_zigzag(root,d,d);
    }
}

void print_level(Node *root, int level){
    if(!root){
        return;
    }
    if(level==1){
        cout<<root->val<<" ";
    }
    else if(level>1){
        print_level(root->left,level-1);
        print_level(root->right,level-1);
    }
}


void print_level_zigzag(Node *root, int level,int dir){
    if(!root){
        return;
    }
    if(level==1){
        cout<<root->val<<" ";
    }
    else if(level>1){
        if(dir%2==0){
            print_level_zigzag(root->left,level-1,dir);
            print_level_zigzag(root->right,level-1,dir);
        }
        else{
            print_level_zigzag(root->right,level-1,dir);
            print_level_zigzag(root->left,level-1,dir);
        }
    }
}




int height(Node *root){
    if(!root){
        return 0;
    }
    else{
        return 1+ std::max(height(root->left),height(root->right));
    }
}