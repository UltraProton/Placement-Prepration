#include <bits/stdc++.h>
using namespace std;
/* A binary tree node has data, pointer to left child
   and a pointer to right child */
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

void serialize(Node *root,vector<int> &);
Node * deSerialize(vector<int> &);
/* Computes the number of nodes in a tree. */
int height(struct Node* node)
{
  if (node==NULL)
    return 0;
  else
    return 1 + max(height(node->left), height(node->right));
}
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
     int N = n;
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
    vector<int> A;
    A.clear();
    serialize(root,A);
  //  for(int i=0;i<A.size();i++)
    //    cout<<A[i]<<" ";
      //  cout<<endl;
    // inorder(root);
     //cout<<endl;
    Node *tree_made = deSerialize(A);
    inorder(tree_made);
    cout<<endl;
  }
  return 0;
}

/*This is a function problem.You only need to complete the function given below*/
/* A binary tree node has data, pointer to left child
   and a pointer to right child  
struct Node
{
    int data;
    Node* left;
    Node* right;
}; */
/*this  function serializes 
the binary tree and stores 
it in the vector A*/

/* 
The idea is to do a BFS on the tree and create a vector which has tree information. The root is at 0 and its children are at 2*0 +1
and 2*0 +2. Same is followed for each node in the level order traversal.

 */


void serialize(Node *root,vector<int> &A)
{
    queue<Node *> Q;

    Node *curr=NULL;

    int idx=0;

    // If we don't have a root then simply return
    if(!root){
        return;
    }

    //Add the root at the 0th index in the vector A
    A.emplace_back(root->data);
    //Push the root at the front
    Q.push(root);

    while (!Q.empty())
    {
        curr= Q.front();
        Q.pop();

        /*The left child has to be stored at idx+1. Eg At starting root is already present at 0th index. So if there is left child
        then it will be stored at index 1 if not then at index 1 we will store -1 to indicate that left child of root is NULL
          */
        idx++;

        if(curr->left){
            Q.push(curr->left);
            A.emplace_back(curr->left->data);
        }
        else{
            A.emplace_back(-1);
        }

        // Same with the right child 
        idx++;

        if(curr->right){
            Q.push(curr->right);
            A.emplace_back(curr->right->data);
        }
        else{
            A.emplace_back(-1);
        }
    }

}
/*this function deserializes
 the serialized vector A*/

// Simply read the input A having the serialized tree in the BFS manner and construct the tree. Deserialization is opposite process.
Node * deSerialize(vector<int> &A)
{
    queue<Node *> Q;
 
    Node *root=NULL;
    Node *curr=NULL;

    int idx=0;

    if(A[0]==-1){
        return NULL;
    }

    root= new Node(A[0]);

    Q.push(root);

    Node *temp=NULL;

    while (!Q.empty())
    {
        curr= Q.front();
        Q.pop();

        idx++;

        if(A[idx]!=-1){
            temp= new Node(A[idx]);
            Q.push(temp);
            curr->left= temp;
        }

        idx++;

        if(A[idx]!=-1){
            temp= new Node(A[idx]);
            Q.push(temp);
            curr->right =temp;
        }

    }

    return root;
}