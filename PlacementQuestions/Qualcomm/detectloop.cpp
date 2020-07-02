#include<bits/stdc++.h>

using namespace std;

typedef struct Node{
    int val;
    struct Node *next;
    Node(int x):val(x),next(NULL){};
}Node;

bool detect_loop_first(Node *head);
bool detect_loop_second(Node *head);
bool detect_loop_third(Node *head);

int main(){
    Node *head= new Node(1);
    head->next=head;
    //head->next= new Node(2);
    head->next->next=head;
    cout<<detect_loop_first(head)<<endl;
    cout<<detect_loop_second(head)<<endl;
    cout<<detect_loop_third(head)<<endl;

    return 0;
}

bool detect_loop_first(Node *head){
    Node *t=head;
    set<Node *> s;
    while(t && t->next){
        if(s.find(t)!=s.end()){
            cout<<"found loop at: "<<t->val<<"\n";
            return true;
        }
        s.insert(t);
        t=t->next;
    }
    return false;
}

bool detect_loop_second(Node *head){
    Node *fast=head;
    Node *slow=head;

    while(slow && fast && fast->next){
        slow=slow->next;
        fast=fast->next->next;
        if(fast==slow){
            return true;
        }
    }

    return false;
}

/* This approach won't work for finding the starting node of the loop in linked list */
bool detect_loop_third(Node *head){
    Node *slow=head;
    Node *fast= head->next;
    /* If we have null list or a list with only one node then return false */
    if(!slow || !fast){
        return false;
    }
    /* The important point is to avoid segfault so we must check fast->next for null pointer */
    while(fast && fast->next){
        if(slow==fast){
            return true;
        }
        slow=slow->next;
        fast=fast->next->next;
    }

    return false;
}