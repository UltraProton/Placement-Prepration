#include<bits/stdc++.h>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};

bool printAncestors(struct Node *root, int target);
int main()
{
  int t;
  struct Node *child;
  scanf("%d", &t);
  while (t--)
  {
     map<int, Node*> m;
     int n;
     scanf("%d",&n);
     struct Node *root = NULL;
     if(n==1)
     {
        int a;
        cin>>a;
        cout<<a<<endl;
     }else{
     while (n--)
     {
        Node *parent;
        char lr;
        int n1, n2;
        scanf("%d %d %c", &n1, &n2, &lr);
      //  cout << n1 << " " << n2 << " " << (char)lr << endl;
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
     int a;
     cin>>a;
    printAncestors(root, a);
  }
  }
  return 0;
}

/*This is a function problem.You only need to complete the function given below*/
/*
Structure of a node is as following
struct Node
{
     int data;
     struct Node* left;
     struct Node* right;
};
*/

// Function should print all the ancestor of the target node
bool printAncestors(struct Node *root, int target)
{
     // Code here
     //* If node is not present then return false;
     if(!root){
         return false;
     }
    //* If the root itself is the target then there are no ancestors of target and simply return true
     if(root->data == target){
         return true;
     }

     //* If the target is present in either root's left or root's right then print the root 

     //? Its basically pre order traversal but in a controlled manner we only print the root->data only when we have found the
     //? the target in either of the left or right subtree of root. 
     /* 
              1
            /   \
           2     3
          / \
         4   5 
        /
       7

       In this tree when we finally find 7 in the left of 4 then the call of 7 will return true to 4 and 4 will be printed
       then 4 will return true to 2 and 2 will be printed and finally 2 will return true to 1 and 1 will be printed. 
       * Here we needed a way to inform the pending calls that a subcall has found the target which means the chain of pending calls
       * above have also found the solution which means we have reached to the target from the ancestors which forms a chain
       * of pending calls

      */

     if(printAncestors(root->left, target) || printAncestors(root->right,target)){
         cout<<root->data<<" ";
         return true;
     }

     //* We were unable to find the target so return false
     return false;
}
