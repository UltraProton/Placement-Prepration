#include <bits/stdc++.h>
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
/* Computes the number of nodes in a tree. */
int height(struct Node* node)
{
  if (node==NULL)
    return 0;
  else
    return 1 + max(height(node->left), height(node->right));
}
int maxLevelSum(Node * root);
/* Function to get diameter of a binary tree */
void inorder(Node *root)
{
    if (root == NULL)
       return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);    
}
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
     cout << maxLevelSum(root) << endl;
  }
  return 0;
}


/*This is a function problem.You only need to complete the function given below*/
/* Tree node structure  used in the program
 struct Node
 {
     int data;
     Node* left, *right;
}; */
/*You are required to complete below method */

//* Go level by level and store the result of the level sum in an array idexed according to the level value
int maxLevelSum(Node * root)
{
   //Your code here
   queue<pair<Node *, int>> Q;
   int level_sum[100];

   memset(level_sum, 0, sizeof(level_sum));

   int curr_level=-1;
   Node *curr_node=NULL;

   pair<Node *, int> curr;

   Q.push(make_pair(root,0));

   while (!Q.empty())
   {
       curr= Q.front();
       Q.pop();
       curr_node= curr.first;
       curr_level=curr.second;

       level_sum[curr_level] += curr_node->data;

       if(curr_node->left){
           Q.push(make_pair(curr_node->left, curr_level+1));
       }

       if(curr_node->right){
           Q.push(make_pair(curr_node->right, curr_level+1));
       }
   }

   int ans=INT_MIN;

   for(int i=0;i<100;i++){
       ans= max(ans, level_sum[i]);
   }

   return ans;
}
