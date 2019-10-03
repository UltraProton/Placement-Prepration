#include<bits/stdc++.h>

using namespace std;

class Node{
    public:
    int val;
    Node *left;
    Node *right;
    Node(int x): val(x), left(NULL), right(NULL){}
};

void vertical_traversal(const Node *root, int h_dist, map<int, vector<int>> &mp);

int main(int argc, char const *argv[])
{
    /* code */
    Node *root= new Node(3);
    root->left= new Node(9);
    root->right= new Node(20);
    root->right->left= new Node(15);
    root->right->right= new Node(7);

    map<int, vector<int>> mp;
    vector<vector<int>> ans;

    vertical_traversal(root, 0 , mp);
    
    for(auto x:mp){
        for(auto y:x.second){
            cout<<y<<" ";
        }
        cout<<endl;
    }

    return 0;
}



void vertical_traversal(const Node *root, int h_dist,  map<int,vector<int>>  &mp){
    queue<pair<const Node *, int>> Q;
    Q.push(make_pair(root,0));

    pair<const Node *, int> curr;
    int curr_dist=0;
    while(!Q.empty()){
        curr= Q.front();
        Q.pop();

        curr_dist= curr.second;
        mp[curr_dist].emplace_back(curr.first->val);
        
        if(curr.first->left){
            Q.push(make_pair(curr.first->left,curr_dist-1 ));
        }
        if(curr.first->right){
            Q.push(make_pair(curr.first->right,curr_dist+1));
        }
    }
}
