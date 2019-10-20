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
    node *Delete_helper(node *root);
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

    node *x= bst.Search(root,5);

    cout<<endl;

    if(x){
        cout<<x->val<<endl;
    }
    

    bst.Delete(root,5);

    x= bst.Search(root,2);

    cout<<endl;

    if(x){
        cout<<x->val<<endl;
    }

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

node * BST :: Search(node *root, int key){
    //If the root is NULL then we don't have the key in the tree or if the root's key is what we are searching then also return root
    if(root==NULL || root->val==key){
        return root;
    }
    //If the above condition is false and the key is greater than the root value then we need to search for the 
    // key in the right subtree of the root 
    if(root->val < key){
        return Search(root->right,key);
    }
    
    //else we need to search for the key in the left subtree of root
    else{
        return Search(root->left,key);
    }
}

/* 3 cases to consider here:
case a: If the node to be deleted has no child then simply remove that node from the tree
case b: If the node to be deleted has one child then replace the child with the node and delete the node from
the tree.

case c: If the node has both the child then find the inorder successor of the node and replace the node with the
inorder successor and delete the node. We can also replace the node with inorder predecessor.


 */
void BST :: Delete(node *root, int key){
    if(!root){
        return;
    }

    if(root->val==key){
        if(!root->left && !root->right){
            delete root;
        }
        else if(root->left && root->right){
            node * temp= Delete_helper(root->right);
            swap(root,temp);
            delete root;
        }
        else if(!root->left){
            swap(root->right, root);
            delete root;
        }
        else{
            swap(root->left,root);
            delete root;
        }
    }

    else if(root->val< key){
        Delete(root->right,key);
    }
    else{
        Delete(root->left, key);
    }
}

node * BST :: Delete_helper(node *root){
    if(!root->left){
        return root;
    }

    return Delete_helper(root->left);
}