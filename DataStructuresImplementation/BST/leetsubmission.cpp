TreeNode* BST :: deleteNode(TreeNode *root, int key){
    if(!root){
        return root;
    }

    if(root->val< key){
        root->right= deleteNode(root->right,key);
    }
    else if(root->val> key){
        root->left= deleteNode(root->left, key);
    }

    else{
        
        //If the current node is leaf node then simply delete it from the tree
        if(!root->left && !root->right){
            delete root;
            //root is deleted so to avoid the dangling pointer set root to NULL
            root=NULL;
        }

        //If we have only one child the belo   
        else if(!root->left){
            swap(root->right, root);
            delete root->right;
        }

        else if(!root->right){
            swap(root->left,root);
            delete root->left;
        }
            
        TreeNode * temp= find_min(root->right);
        root->val= temp->val;
        root->right= deleteNode(root->right,temp->val);   
    }

    return root;
}

TreeNode * BST :: find_min(node *root){
    TreeNode *temp=root;
    while(temp && temp->left){
        temp=temp->left;
    }

    return temp;
}