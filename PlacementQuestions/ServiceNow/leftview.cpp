#include<bits/stdc++.h>

using namespace std;

class node{
    public:
    int val;
    node *left;
    node *right;
    node(int val): val(val), left(NULL), right(NULL){}
};

void left_view(node *root, int level, int *max_level);

int main(int argc, char const *argv[])
{
    /* code */
    node *root=new node(1);
    root->left= new node(2);
    root->right=new node(3);
    root->right->right= new node(4);
    int *max_level;
    *max_level= INT_MIN;

    left_view(root,0,max_level);
    
    return 0;
}



void left_view(node *root, int level, int *max_level){
    if(root){
        if(*max_level < level){
            *max_level= level;
            cout<<root->val<<endl;
        }

        left_view(root->left,level+1,max_level);
        left_view(root->right,level+1, max_level);
    }
}
