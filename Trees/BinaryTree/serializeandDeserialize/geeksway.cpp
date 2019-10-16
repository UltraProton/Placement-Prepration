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

//* Just do a preorder traversal and store -1 in case of NULL and actual root value in case of not NULL value

void serialize(Node *root,vector<int> &A)
{
 if(!root){
     A.emplace_back(-1);
     return;
 }
 else{
     A.emplace_back(root->data);
     serialize(root->left,A);
     serialize(root->right, A);
 }   
}
/*this function deserializes
 the serialized vector A*/

// We are taking a root as parameter it can be avoided as well plus the code is not very clear
Node *deSerializeHelper1(Node *root, vector<int> &A,int &idx){
    // If we have reached the end of the input of the element at current index is -1 { We have a NULL node at the current index }
    if(idx >= A.size() || A[idx]==-1){
        idx=idx+1;//Incrementing this index is also necessary in case we have a NULL node at the current index
        return NULL;
    }   

    //Give memory to the root node with the value at the current index
    root= new Node(A[idx]);
    idx= idx+1;//Move to the next index
    root->left= deSerializeHelper1(root->left, A, idx);//deserialize the left subtree
    root->right= deSerializeHelper1(root->right, A, idx);//deserialize the right subtree

    return root;//Finally return the root node
}

// We are taking a root as parameter it can be avoided as well plus the code is not very clear
Node *deSerializeHelper2(vector<int> &A,int &idx){
    // If we have reached the end of the input of the element at current index is -1 { We have a NULL node at the current index }
    if(idx >= A.size() || A[idx]==-1){
        idx=idx+1;//Incrementing this index is also necessary in case we have a NULL node at the current index
        return NULL;
    }   

    //Give memory to the root node with the value at the current index
    Node *root= new Node(A[idx]);
    idx= idx+1;//Move to the next index
    root->left= deSerializeHelper2(A, idx);//deserialize the left subtree
    root->right= deSerializeHelper2(A, idx);//deserialize the right subtree

    return root;//Finally return the root node
}


Node * deSerialize(vector<int> &A)
{
    Node *root;
    int idx=0;
    root=  deSerializeHelper2(A,idx);
    
    return root;
}