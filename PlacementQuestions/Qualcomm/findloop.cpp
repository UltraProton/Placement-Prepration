#include<bits/stdc++.h>

using namespace std;

typedef struct Node{
    int val;
    struct Node *next;
    Node(int x):val(x),next(NULL){};
}Node;

Node *find_loop(Node *head);

int main(){
    Node *head= new Node(1);
    head->next=head;
    //head->next= new Node(2);
    head->next->next=head;

    cout<<find_loop(head)->val<<endl;

    return 0;
}

Node *find_loop(Node *head){
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
        return nullptr;
    }

    slow=head;
    while(slow!=fast){
        slow=slow->next;
        fast=fast->next;
    
    }

    return slow;
}