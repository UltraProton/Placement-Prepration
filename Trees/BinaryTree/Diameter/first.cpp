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

int height(Node *root){
    if(!root){
        return 0;
    }

    else{
        return 1+ max(height(root->left), height(root->right));
    }
}



/* 
! Time complexity: We are doing a preorder traversal of the tree and for each node we are calling height subroutine . So if there are
! n nodes then the time complexity will be O(n^2)
 */


/* 
* Geeks implementation says that diameter of binary tree is the 

* the diameter of T’s left subtree
* the diameter of T’s right subtree
* the longest path between leaves that goes through the root of T (this can be computed from the heights of the subtrees of T)

* max(diameter of left subtree, diameter of right subtree, height of left subtree+height of right subtree +1) 

? The below code also follows above strategy but not clearly written. My thinking in this code: Do a preorder traversal of the 
? tree and for each node find whether the diameter of the subtree rooted at current root can be called diameter of whole tree.

 */



void diameter_util(Node *root, int &d){
    if(!root){
        return;
    }
    //int d_temp= INT_MIN;

    //* Find the height of left subtree 
    int h_l= height(root->left);
    //* Find the height of right subtree
    int h_r= height(root->right);

    //* Take the max of diamter temporary
    //d_temp= max(d_temp,h_l + h_r +1);

    //d= max(d_temp, d);

    d= max(d, h_l+ h_r+1);

    diameter_util(root->left, d);
    diameter_util(root->right, d);

}

int diameter(Node *root){
    int d=INT_MIN;
    
    diameter_util(root,d);

    return d;

}

