#include<bits/stdc++.h>

using namespace std;

struct node{
    int val;
    node *left;
    node *right;
    node (int x): val(x), left(NULL), right(NULL){} 
};

bool helper(node *root, int target, unordered_map<int,int> &mp);
bool isPairPresent(struct node *root, int target);

node * insert(node *root, int val){
    if(!root){
        return new node(val);
    }
    if(root->val < val){
        root->right= insert(root->right, val);
    }
    if(root->val > val){
        root->left= insert(root->left,val);
    }

    /* We need to return this root because when we backtrack we will link the nodes again at their appropriate 
    positions.
     */
    return root;
}

node *inorder(node *root){
    if(root){
        inorder(root->left);
        cout<<root->val<<" ";
        inorder(root->right);
    }
}

int main(){
    node *root=NULL;
    //root remains NULL if the following step is not done
    root= insert(root,15);
    insert(root,10);
    insert(root,20);
    insert(root,8);
    insert(root,12);
    insert(root,16);
    insert(root,25);

    //inorder(root);

    cout<<isPairPresent(root, 33)<<endl;
    return 0;
}

bool helper(node *root, int target, unordered_map<int,int> &mp){
    if(!root){
        return false;
    }

    //cout<<"helper( root= "<<root->val<<" "<<endl;

    //If we find the complement of the current in map then we have found 2 no's sum of which are equal to 
    // target
    if(mp.find(target-root->val)!=mp.end()){
            return true;
    }
    
    //make an entry of the current element in the map so if it is a complement of to be seen element
    //then we can simply say we have the pair with sum equal to target
    mp[root->val]=1;

    //find if we can get the result either on the left subtree or the right subtree    
    return (helper(root->left, target, mp) || helper(root->right, target,mp));
    
}


bool isPairPresent(struct node *root, int target)
{
//add code here.
if(!root){
    cout<<"x"<<endl;
    return false;
}
unordered_map<int,int> mp;
return helper(root, target, mp);
}
