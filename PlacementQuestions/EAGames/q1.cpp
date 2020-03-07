#include<bits/stdc++.h>

using namespace std;

class node{
    public:
    int val;
    node * next;
    node(val): val(val), next(NULL){}
};
node *reverse(node *);

int main(){
    node *h= new node(1);
    h->next= new node(2);
    h->next->next=new node(3);
}

node *reverse(node *head){
    node *p=NULL;
    node *c=head;
    node *n=NULL;
    while(c){
        n=c->next;
        c->next=p;
        p=c;
        c=n;
    }

    head=p;
    return head;
}