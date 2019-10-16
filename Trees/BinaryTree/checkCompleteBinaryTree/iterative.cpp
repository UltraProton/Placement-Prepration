#include<bits/stdc++.h>

using namespace std;

typedef struct node{
    int val;
    node *left;
    node *right;
    node(){}
    node(int x): val(x), left(NULL), right(NULL){}
}Node;


bool is_complete(Node *root);

int main(int argc, char const *argv[])
{
    Node *root= new Node(1);
    root->left= new Node(2);
    root->right=NULL;

    cout<<is_complete(root)<<endl;

    return 0;
}


//* Run a BFS on the tree starting from the root node
bool is_complete(Node *root){
    queue<Node *> Q;
    Q.push(root);

    Node *curr=NULL;


    bool had_left=false; // Stores whether the previous node had a left child or not
    bool had_right=false;// Stores whether the previous node had a right child or not

    if(root->left){
        had_left=true;        
    }
    if(root->right){
        had_right=true;
    }

    /* 
    Special case:           1
                           /
                          2

    This case should be handled separately.
     */

    //* Special case handling
    if(had_left && !had_right){
        if(!root->left->left && !root->left->right){
            return true;
        }
    }

    //* If the root doesn't follow this then we can simply return
    if(!had_left && had_right){
        return false;
    }

    while (!Q.empty())
    {
        curr= Q.front();
        Q.pop();
        
        //* If the current node has left node but the previous node didn't have right then its not complete tree
        /* 
        Case:       1
                   / \
                  2   4
                 /   /
                3   5
         */

        if(curr->left){
            if(!had_right){
                return false;
            }
            had_left=true;
            Q.push(curr->left);
        }

        // We can safely say that current node has left
        else{
            had_left=false;
        }

        //* If for any node we dont have curr->left but we have curr->right then we can return false immediately 
        if(!curr->left && curr->right){
            return false;
        }

        if(curr->right){
            had_right=true;
            Q.push(curr->right);
        }
        else{
            had_right=false;
        }
    }

    return true;
    
}
