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

void topView(struct Node *root);

/* Driver program to test size function*/
int main()
{
  int t;
  struct Node *child;
  cin >> t;
  while (t--)
  {
     map<int, Node*> m;
     int n;
     cin >> n;
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
     bottomView(root);
     cout << endl;
  }
  return 0;
}


/* Here we want the bottom most node on a horizonatal level. This is exact opposite of topView() */

void bottomView(Node *root){
    map<int,int> mp;
    queue<pair<Node *, int>> Q;
    int h_dist=0;
    Q.push(make_pair(root,0));
    pair<Node *, int> curr;
    
    while(!Q.empty()){
        curr=Q.front();
        Q.pop();
        h_dist= curr.second;

        mp[h_dist]=curr.first->data;
            //cout<<curr.first->data<<" ";

        if(curr.first->left){
            Q.push(make_pair(curr.first->left, h_dist-1));
        }

        if(curr.first->right){
            Q.push(make_pair(curr.first->right, h_dist+1));
        }

    }

    for(auto x:mp){
        cout<<x.second<<" ";
    }
}
