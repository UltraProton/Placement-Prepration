/* 

https://www.geeksforgeeks.org/find-the-maximum-sum-path-in-a-binary-tree/

? Root to leaf max sum path

 */

#include<bits/stdc++.h>

using namespace std;

typedef struct node{
    int data;
    struct node *left;
    struct node *right;
    node(){}
    node(int val):data(val), left(NULL), right(NULL){}

}Node;

int max_sum_path(Node *root);

int main(int argc, char const *argv[])
{
    node* root = NULL; 
  
    /* Constructing tree given in the above figure */
    root = new Node(10); 
    root->left = new Node(-2); 
    root->right = new Node(7); 
    root->left->left = new Node(8); 
    root->left->right = new Node(-4); 
  
    
    int sum = max_sum_path(root); 
    
    cout << "\nSum of the nodes is " << sum; 
    
    return 0; 
}

int max_sum_path(Node *root){
    if(!root){
        return 0;
    }

    int l_sum= max_sum_path(root->left);
    int r_sum= max_sum_path(root->right);

    return root->data + max(l_sum,r_sum);
}