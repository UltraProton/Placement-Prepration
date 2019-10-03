#include <bits/stdc++.h>
#include<stdio.h>

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
// A wrapper over leftViewUtil()
void leftView(struct Node *root);
/* Driver program to test size function*/
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
     leftView(root);
     std::cout << endl;
  }
  return 0;
}

/*This is a function problem.You only need to complete the function given below*/
/* A binary tree node
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
// A wrapper over leftViewUtil()
void leftView(Node *root)
{
   // Your code here
   queue<pair<Node*,int>> Q;
   map<int,int> mp;
   Q.push(make_pair(root,0));
   pair<Node *,int> curr;
   int curr_level=0;

   while(!Q.empty()){
       curr= Q.front();
       Q.pop();
       curr_level=curr.second;
       if(mp.find(curr_level)==mp.end()){
           mp[curr_level]=curr.first->data;
           std::cout<<curr.first->data<<" ";
       }
       if(curr.first->left){
           Q.push(make_pair(curr.first->left,curr_level+1));
       }

       if(curr.first->right){
           Q.push(make_pair(curr.first->right,curr_level+1));
       }
   }


}