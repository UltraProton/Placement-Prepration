#include<bits/stdc++.h>

using namespace std;

typedef struct node {
    int data;
    struct node *next;
}Node;

Node *merge_inplace(Node *first, Node* second);
Node *newNode(int data);

int main(void){
    Node *first= newNode(10);
    first->next= newNode(50);
    first->next->next = newNode(70);

    first->next->next->next= newNode(80);

    Node *second= newNode(5);
    second->next= newNode(10);
    second->next->next= newNode(90);
    second->next->next->next= newNode(120);

    Node *newlist= merge_inplace(first, second);

    Node *temp= newlist;
    while(temp){
        cout << temp->data << " " ;
        temp=temp->next;
    }

    return 0;
}

Node *newNode(int x){
    Node* temp = new Node;
    temp->data= x;
    temp->next= NULL;
    return temp;
}

Node *merge_inplace(Node *first, Node *second){
    Node *ans= NULL;
    Node *current_min= NULL;

    if(!first)
        return second;
    if(!second)
        return first;

    if(first->data <= second->data){
        current_min= first;
        first=first->next;
    }

    else{
        current_min= second;
        second=second->next;
    }

    ans= current_min;

    while(first && second){
        if(first->data <= second->data){
            current_min->next= first;
            current_min= first;
            first= first->next;
        }
        else{
            current_min->next= second;
            current_min=second;
            second= second->next;
        }
    }

    if(!first)
        current_min->next= second;
    if(!second)
        current_min->next= first;

    return ans;
}


