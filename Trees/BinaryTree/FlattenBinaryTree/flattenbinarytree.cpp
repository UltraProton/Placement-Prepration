#include<bits/stdc++.h>

using namespace std;

struct TreeNode{
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode (int x): data(x), left(NULL),right(NULL){}
};

void flatten(struct TreeNode *root)
{
    struct TreeNode *curr = root;
    while (curr != NULL)
    {
        if (curr->left != NULL)
        {
            if (curr->right != NULL)
            {
                struct TreeNode *next = curr->left;
                if (next->right != NULL)
                {
                    while (next->right != NULL)
                    {
                        next = next->right;
                    }
                }
                next->right = curr->right;
            }
            curr->right = curr->left;
            curr->left = NULL;
        }
        curr = curr->right;
    }
}