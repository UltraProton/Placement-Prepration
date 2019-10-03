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
/* Function to get diameter of a binary tree */
int diameter(struct Node * tree);
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
     cout<<diameter(root) << endl;
  }
  return 0;
}


/* 
! Time complexity: We are doing a preorder traversal of the tree and for each node we are calling height subroutine . So if there are
! n nodes then the time complexity will be O(n^2)
 */



/* 
* Initially we were computing height for every node in the tree which can be done in single pass over the tree. When we are computing
* diameter we can get height of each subtree rooted at root and alongside store the max value of diameter of the tree.

? Diameter of binary tree is nothing but max value of (height of left subtree+ height of right subtree +1 ) so we can just use the
? height function to calculate the diameter

 */ 
int height_util(Node *root, int &d){
    if(!root){
        return 0;
    }
    //int d_temp= INT_MIN;

    //* Find the height of left subtree 
    int h_l=  height_util(root->left, d);
   
    //* Find the height of right subtree
    int h_r=  height_util(root->right, d);

    if(h_l+h_r+1 > d){
        d= h_l+ h_r +1;
    }
    
    return 1+max(h_l,h_r);
   
}

int diameter(Node *root){
    int d=INT_MIN;
    
    height_util(root,d);

    return d;

}

