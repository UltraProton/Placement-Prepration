/* 

https://practice.geeksforgeeks.org/problems/maximum-path-sum/1

? This problem asks for max path sum between 2 leaves. 

 */

#include<bits/stdc++.h>

using namespace std;

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
int maxPathSum(struct Node *root);
void insert(Node *root, int a1,int a2, char lr){
	if(root==NULL)
		return ;
	if(root->data==a1){
		switch(lr){
			case 'L':root->left=new Node(a2);
					break;
			case 'R':root->right=new Node(a2);
					break;
		}
	}
	insert(root->left,a1,a2,lr);
	insert(root->right,a1,a2,lr);
}
void inorder(Node *root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right)
;}
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		Node *root=NULL;
		while(n--){
			int a1,a2;
			char lr;
			cin>>a1>>a2>>lr;
			if(root==NULL){
				root=new Node(a1);
				switch(lr){
					case 'L':root->left=new Node(a2);
							break;
					case 'R':root->right=new Node(a2);
							break;
				}
			}
			else
				insert(root,a1,a2,lr);
		}
		//inorder(root);
		//cout<<endl;
		cout<<maxPathSum(root)<<endl;		
	}
}

/*This is a function problem.You only need to complete the function given below*/
/*Complete the function below
Node is as follows
struct Node{
	int data;
	Node *left, *right;
};
*/

//* When we think of path between 2 leaves then we can think of diameter of tree


int max_Path_Sum_Util(struct Node *root, int &ans){

    if(!root){
        return 0;
    }	

    int l_sum= max_Path_Sum_Util(root->left,ans);
    int r_sum= max_Path_Sum_Util(root->right,ans);

    if(l_sum +r_sum + root->data > ans){
        ans= l_sum + r_sum + root->data;
    }

    return root->data + max(l_sum, r_sum);

}


int maxPathSum(struct Node *root)
{
    int ans=INT_MIN;

    max_Path_Sum_Util(root,ans);

	return ans;
}
