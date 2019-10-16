#include<bits/stdc++.h>

using namespace std;

class TreeNode{
    public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(NULL), right(NULL){}
};

void vertical_traversal(const TreeNode *root, map<int, vector<pair<int,pair<int,int>>>> &mp);
bool cmp(pair<int,pair<int,int>> &p1, pair<int,pair<int,int>> &p2);

int main(int argc, char const *argv[])
{
    /* code */
    TreeNode *root= new TreeNode(3);
    root->left= new TreeNode(9);
    root->right= new TreeNode(20);
    root->right->left= new TreeNode(15);
    root->right->right= new TreeNode(7);

    map<int, vector<pair<int,pair<int,int>>>> mp;
    vector<vector<int>> ans;

    vertical_traversal(root, mp);
    vector<int> temp;
    
    for(auto x:mp){
        std::sort(x.second.begin() , x.second.end(), cmp);
        temp.clear();
        for(auto y:x.second){
                temp.emplace_back(y.first);
        }
        ans.push_back(temp);
    }

    for(auto x:ans){
        for(auto y:x){
            cout<<y<<" ";
        }
        cout<<endl;
    }

    return 0;
}



void vertical_traversal(const TreeNode *root, map<int,vector<pair<int,pair<int,int>>>>  &mp){
    queue<pair<const TreeNode *, pair<int,int>>> Q;
    Q.push(make_pair(root,make_pair(0,0)));

    pair<const TreeNode *, pair<int,int>> curr;
    int h_dist=0;
    int v_dist=0;
    while(!Q.empty()){
        curr= Q.front();
        Q.pop();

        h_dist= curr.second.first;
        v_dist= curr.second.second;

        mp[h_dist].emplace_back(make_pair(curr.first->val,make_pair(h_dist,v_dist)));
        
        if(curr.first->left){
            Q.push(make_pair(curr.first->left,make_pair(h_dist-1,v_dist-1 )));
        }
        if(curr.first->right){
            Q.push(make_pair(curr.first->right,make_pair(h_dist+1,v_dist-1)));
        }
    }
}


bool cmp(pair<int,pair<int,int>> &p1, pair<int,pair<int,int>> &p2){

    if(p1.second.first==p2.second.first && p1.second.second==p2.second.second){
        return p1.first < p2.first;
    }
    
    else if(p1.second.first== p2.second.first){
        return p1.first > p2.first;
    }

    return false;
}