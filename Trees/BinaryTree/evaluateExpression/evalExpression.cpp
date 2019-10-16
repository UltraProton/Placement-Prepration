/* 

https://practice.geeksforgeeks.org/problems/expression-tree/1/?ref=self

 */

#include<bits/stdc++.h>
using namespace std;
struct node
{
	string data;
	struct node *left;
	struct node *right;
	
	node(string x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};
int evalTree(node *);
int main()
{
    int t;
    cin>>t;
    while(t--){
    int n;
    cin>>n;
	string s[n];
	for(int i=0;i<n;i++)
		cin>>s[i];
	int p=0;
	node *root = new node(s[p]);
	queue<node *> q;
	q.push(root);
    p=1;
	while(!q.empty())
	{
		node *f = q.front();
		q.pop();
		node  *l,*r;
		if(p!=n){
        l=new node(s[p]);
		f->left = l;
		p++;
		q.push(l);
	    }
	    else
	    {
	    	f->left = NULL;
	    }
		if(p!=n){
        r=new node(s[p]);
		f->right = r;
		p++;
		q.push(r);
		}else
		{
			f->right=NULL;
		}
	}
	cout<<evalTree(root)<<endl;
    }
}

/*This is a function problem.You only need to complete the function given below*/
/*The structure of node is as follows
struct node{
	string data;
	node *left;
	node *right;
};
*/
/*You are required to complete below method */
int convert(string  &s){
    if(s[0]=='+' || s[0]=='-' || s[0]== '/' || s[0]=='*'){
        return s[0];
    }

    else{
        int ans=0;
        for(int i=0;i<s.size();i++){
            ans= ans*10 + s[i]-'0';
        }

        return ans;
    }
}

int evaluate(int x, int y, int op){
    switch (op)
    {
    case '+' : return (x+y);  
        break;
    case '-': return (x-y);

    case '*': return (x*y);

    case '/': return (x/y);
    
    default:
        break;
    }
}

int evalTree(node* root)
{
    //* Here we don't have a base case because the tree will never have case where root == NULL
    int symbol= convert(root->data);//* Get what is there at the root

    //* If it is an operator
    if(symbol =='+' || symbol=='-' || symbol=='*' || symbol=='/'){
        int l_ans= evalTree(root->left);//* Get the result of the left subtree
        int r_ans= evalTree(root->right);//* Get the result of the right subtree

        int ans= evaluate(l_ans, r_ans, symbol); //* Return the ans by combining the result of the two subtrees

        return ans;
    }

    //* If it is not a operator then it must be operand so we just return it
    else{
        return symbol;
    }
}
