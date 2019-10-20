#include<bits/stdc++.h>

using namespace std;

class node{
    public:
    int val;
    node *left;
    node *right;
    node(int val): val(val), left(NULL), right(NULL){}
};

class BST{
    public:
    node *Insert(node *root, int key);
    node *Search(node *root, int key);
    void Delete(node *root, int key);
    void print_inorder(node *root);
};


int main(int argc, char const *argv[])
{
    /* code */

    BST bst;
    
    node *root =NULL;

    root= bst.Insert(root, 1);
    
    bst.Insert(root,2);
    bst.Insert(root,5);

    bst.print_inorder(root);

    return 0;
}


node * BST :: Insert(node *root, int key){
    if(!root){
        node *t= new node(key);
        return t;
    }

    //If the root val is greater than or equal to the key to be inserted then insert the key on the left sub tree of the root
    // and link the updated left sub tree back to the left sub tree of the root 
    if(root->val >= key){
        root->left= Insert(root->left,key);
    }

    // If the root val is lesser than the key value to be inserted then insert it in the right subtree of the root and link the updated
    // right sub tree back to the root right
    else if(root->val < key){
        root->right= Insert(root->right, key);
    }

    //return the updated root back
    return root;
}


void BST :: print_inorder(node *root){
    if(root){
        print_inorder(root->left);
        cout<<root->val<<" ";
        print_inorder(root->right);
    }
}