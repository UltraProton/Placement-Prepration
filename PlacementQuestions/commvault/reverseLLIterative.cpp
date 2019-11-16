#include<bits/stdc++.h>

using namespace std;

class Node{
    public:
    int val;
    Node *next;
    Node(int val):val(val),next(NULL){}
};

Node *reverse(Node *head);

int main(){
    Node *head=new Node(1);
    head->next= new Node(2);
    head->next->next= new Node(3);

    head= reverse(head);
    Node *temp=head;
    while(temp){
        cout<<temp->val<<" ";
        temp=temp->next;
    }

    return 0;
}

Node *reverse(Node *head){
    Node *prev=NULL;
    Node *curr=head;
    Node *n= NULL;

    while(curr){
        n=curr->next;
        curr->next=prev;
        prev=curr;
        curr=n;
    }

    return prev;
}