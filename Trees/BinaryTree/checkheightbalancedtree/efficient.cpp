/* 

https://practice.geeksforgeeks.org/problems/check-for-balanced-tree/1/?ref=self

 */

#include <bits/stdc++.h>
using namespace std;
/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
bool isBalanced(struct Node *root);
/* Helper function that allocates a new node with the
   given data and NULL left and right pointers. */
/* Driver program to test size function*/
int main()
{
  int t;
  scanf("%d", &t);
  while (t--)
  {
     map<int, Node*> m;
     int n;
     scanf("%d",&n);
     struct Node *root = NULL;
     struct Node *child;
     while (n--)
     {
        Node *parent;
        char lr;
        int n1, n2;
        scanf("%d %d %c", &n1, &n2, &lr);
        if (m.find(n1) == m.end())
        {
           parent = new Node(n1);
           m[n1] = parent;
           if (root == NULL)
             root = parent;
        }
        else
           parent = m[n1];
        child = new Node(n2);
        if (lr == 'L')
          parent->left = child;
        else
          parent->right = child;
        m[n2]  = child;
     }
     cout << isBalanced(root) << endl;
  }
  return 0;
}


/*This is a function problem.You only need to complete the function given below*/
/* A binary tree node structure
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */
// This function should return tree if passed  tree 
// is balanced, else false. 
int height(Node *root){
    if(!root){
        return 0;
    }
    else{
        return 1+ max(height(root->left), height(root->right));
    }
}


/* 
? The idea is to compute the height in the same function and use the result of subcalls to make a decision

 */



int efficient(Node *root, bool &ans){
    if(!root){
        return 0;
    }

    //* find the height of the left sub tree 
    int l_h= efficient(root->left,ans);
    //* find the height of the right sub tree
    int r_h= efficient(root->right,ans);

    //* If the tree rooted at root is height imbalanced then we change the ans to false
    if(abs(r_h-l_h)>1){
        ans= false;
    }

    //* return the max height
    return 1+ max(l_h, r_h);
}

bool isBalanced(Node *root)
{
    
    bool ans=true;
    //* ans will be changed in this call
    efficient(root,ans);

    return ans;

}
