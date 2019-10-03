/* 

https://practice.geeksforgeeks.org/problems/check-if-subtree/1/?ref=self

 */

#include <cstring>
#include <iostream>
#include <map>
using namespace std;

#define MAX 1000
// Structure of a tree node
struct Node {
    int data;
    struct Node *left;
    struct Node *right;
    Node(int x) {
        data = x;
        left = right = NULL;
    }
};
bool isSubtree(Node *T, Node *S);
void storeInorder(Node *, char[], int &);
void storePreOrder(Node *, char[], int &);
bool is_identical(Node *root1, Node *root2);

// Driver program to test above function
int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        struct Node *child = NULL;
        map<int, Node *> m;
        int n;
        scanf(" %d", &n);
        struct Node *t2 = NULL;
        while (n--) {
            Node *parent;
            char lr;
            int n1, n2;
            scanf("%d %d %c", &n1, &n2, &lr);
            if (m.find(n1) == m.end()) {
                parent = new Node(n1);
                m[n1] = parent;
                if (t2 == NULL) t2 = parent;
            } else
                parent = m[n1];
            child = new Node(n2);
            if (lr == 'L')
                parent->left = child;
            else
                parent->right = child;
            m[n2] = child;
        }
        struct Node *child1;
        map<int, Node *> m1;
        int nodes;
        scanf("%d", &nodes);
        struct Node *t1 = NULL;
        while (nodes--) {
            Node *parent1;
            char lr1;
            int n3, n4;
            scanf("%d %d %c", &n3, &n4, &lr1);
            if (m1.find(n3) == m1.end()) {
                parent1 = new Node(n3);
                m1[n3] = parent1;
                if (t1 == NULL) t1 = parent1;
            } else
                parent1 = m1[n3];
            child = new Node(n4);
            if (lr1 == 'L')
                parent1->left = child;
            else
                parent1->right = child;
            m1[n4] = child;
        }
        cout << isSubtree(t1, t2);
        cout << endl;
    }
}

/*This is a function problem.You only need to complete the function given below*/
/* A binary tree node
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
 */
/*you are required to
complete this function */
bool is_subtreeUtil(Node *t1, Node *t2){
    if(t1){
        //* If t2 lies in the left subtree of t1
        bool l= is_subtreeUtil(t1->left,t2);
        //* If t2 lies in the right subtree of t1
        bool r= is_subtreeUtil(t1->right,t2);
        //* If both the tree are identical
        bool x= is_identical(t1,t2);

        //* If any of the above 3 conditions are true then t2 is a subtree of t1
        return (l||r||x);
    }

    return false;
}

bool isSubtree(Node* T1, Node* T2) {
    return is_subtreeUtil(T1,T2);
}


bool is_identical(Node *root1, Node *root2){
    if(!root1 && !root2){
        return true;
    }

    if(!root1 && root2 || !root2 && root1){
        return false;
    }

    if(is_identical(root1->left, root2->left) && is_identical(root1->right , root2->right)){
        if(root1->data == root2->data){
            return true;
        }
        else{
            return false;
        }
    }

    return false;
}