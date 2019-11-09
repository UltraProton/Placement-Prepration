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
    //find the min node in the bst
    node *find_min(node *root);
    //returns the root of the tree after the delete operation
    node *deleteNode(node *root, int key);
    void print_inorder(node *root);
};


int main(int argc, char const *argv[])
{
    BST bst;   
    node *root =NULL;

    root = bst.Insert(root, 50); 
    root = bst.Insert(root, 30); 
    root = bst.Insert(root, 20); 
    root = bst.Insert(root, 40); 
    root = bst.Insert(root, 70); 
    root = bst.Insert(root, 60); 
    root = bst.Insert(root, 80); 
  
    printf("Inorder traversal of the given tree \n"); 
    bst.print_inorder(root); 
  
    printf("\nDelete 20\n"); 
    root = bst.deleteNode(root, 20); 
    printf("Inorder traversal of the modified tree \n"); 
    bst.print_inorder(root); 
  
    printf("\nDelete 30\n"); 
    root = bst.deleteNode(root, 30); 
    printf("Inorder traversal of the modified tree \n"); 
    bst.print_inorder(root); 
  
    printf("\nDelete 50\n"); 
    root = bst.deleteNode(root, 50); 
    printf("Inorder traversal of the modified tree \n"); 
    bst.print_inorder(root); 
  
    return 0;
}


node * BST :: Insert(node *root, int key){
    //This base case is very important
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
node* BST :: deleteNode(node *root, int key){
    if(!root){
        return root;
    }

    if(root->val< key){
        root->right= deleteNode(root->right,key);
    }
    else if(root->val> key){
        root->left= deleteNode(root->left, key);
    }

    else{
        
        //If the current node is leaf node then simply delete it from the tree
        if(!root->left && !root->right){
            delete root;
            //root is deleted so to avoid the dangling pointer set root to NULL
            root=NULL;
        }

        //If we have only one child the belo   
        else if(!root->left){
            node *temp= root;
            root=root->right;
            delete temp;
        }

        else if(!root->right){
            node *temp= root;
            root=root->left;
            delete temp;
        }
            
        node * temp= find_min(root->right);
        root->val= temp->val;
        root->right= deleteNode(root->right,temp->val);   
    }

    return root;
}

node * BST :: find_min(node *root){
    node *temp=root;
    while(temp && temp->left){
        temp=temp->left;
    }

    return temp;
}