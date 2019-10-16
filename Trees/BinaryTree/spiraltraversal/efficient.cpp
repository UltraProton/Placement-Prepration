#include<bits/stdc++.h>
using namespace std;
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
void printSpiral(struct Node *root);
/* Driver program to test above functions*/
int main()
{
   int t;
  scanf("%d", &t);
  while (t--)
  {
     map<int, Node*> m;
     int n;
     scanf("%d",&n);
     Node *root = NULL;
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
        Node *child = new Node(n2);
        if (lr == 'L')
          parent->left = child;
        else
          parent->right = child;
        m[n2]  = child;
     }
    printSpiral(root);
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
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
}; */

int height(Node *root){
    if(!root){
        return 0;
    }
    else{
        return 1+ max(height(root->left) , height(root->right));
    }
}

/* 
* Worst case time complexity: O(n^2) in case of skewed trees

 */


// void print_level(Node *root, int curr_level, int level){
//     if(root){
//         if(level%2){
//             if(curr_level==level){
//                 cout<<root->data<<" ";
//             }
//             print_level(root->right, curr_level+1, level);
//             print_level(root->left, curr_level+1, level);
//         }
//         else{
//             if(curr_level==level){
//                 cout<<root->data<<" ";
//             }

//             print_level(root->left, curr_level+1, level);
//             print_level(root->right, curr_level+1, level);
//         }
//     }
// }

void printSpiral(Node *root)
{
    stack<Node *> st1;
    stack<Node *> st2;

    Node *curr=NULL;

    st1.push(root);

    while (!st1.empty() || !st2.empty())
    {
        while (!st1.empty())
        {
            curr= st1.top();
            cout<<curr->data<<" ";
            st1.pop();
            if(curr->right){
                st2.push(curr->right);
            }
            if(curr->left){
                st2.push(curr->left);
            }        
        }

        while (!st2.empty())
        {
            curr= st2.top();
            cout<<curr->data<<" ";
            st2.pop();
            if(curr->left){
                st1.push(curr->left);
            }
            if(curr->right){
                st1.push(curr->right);
            }
        }
        
    }
}
