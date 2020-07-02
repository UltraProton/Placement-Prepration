#include<bits/stdc++.h>

using namespace std;

typedef struct Node{
    int val;
    struct Node *next;
    Node(int x):val(x),next(NULL){};
}Node;

void remove_loop(Node *head);

int main(){
    Node *head= new Node(1);
    head->next=head;
    //head->next= new Node(2);
    head->next->next=head;

    // cout<<remove_loop(head)->val<<endl;
    remove_loop(head);
    Node *t=head;
    while(t){
        cout<<t->val<<" ";
        t=t->next;
    }

    return 0;
}

void remove_loop(Node *head){
    Node *slow=head;
    Node *fast=head;
    
    while(fast && fast->next){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast){
            break;
        }
    }

    if(fast!=slow){
        return;
    }

    //Find the starting node of the loop
    slow=head;
    while(slow!=fast){
        slow=slow->next;
        fast=fast->next;
    
    }

    //Remove the loop 
    Node *t= slow;
    while(t->next!=slow){
        t=t->next;
    }

    t->next=nullptr;
}