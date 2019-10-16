#include<bits/stdc++.h>

using namespace std;

class Node{
    public:
    int val;
    Node *left;
    Node *right;
    Node(int x): val(x), left(NULL), right(NULL){}
};

bool cmp(pair<int,pair<int,int>> &p1, pair<int,pair<int,int>> &p2);
void vertical_traversal(const Node *root, int h_dist, int v_dist,  map<int, vector<pair<int,pair<int,int>>>> &mp);

int main(int argc, char const *argv[])
{
    /* code */
    Node *root= new Node(3);
    root->left= new Node(9);
    root->right= new Node(20);
    root->right->left= new Node(15);
    root->right->right= new Node(7);

    map<int, vector<pair<int,pair<int,int>>>> mp;

    vertical_traversal(root, 0,0, mp);
    
    for(auto x:mp){
        std::sort(x.second.begin(), x.second.end(),cmp);
        for(auto y:x.second){
            cout<<y.first<<" ";
        }
        cout<<endl;
    }




    return 0;
}




void vertical_traversal(const Node *root, int h_dist, int v_dist,  map<int,vector<pair<int,pair<int,int>>>>  &mp){
    if(root){
        mp[h_dist].push_back(make_pair(root->val,make_pair(h_dist,v_dist)));
        vertical_traversal(root->left, h_dist-1,v_dist-1,mp);
        vertical_traversal(root->right, h_dist+1,v_dist-1, mp);
    }
}
