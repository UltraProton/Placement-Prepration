#include<bits/stdc++.h>

using namespace std;

class node{
    public:
    int val;
    node* next;
    node(int val): val(val), next(NULL){}
};

bool detect_cycle(node *head);

int main(){
    node *head=new node(1);
    head->next=new node(2);
    //head->next->next=head->next;

    cout<<detect_cycle(head)<<endl;
    
    return 0;
}

bool detect_cycle(node *head){
    if(!head){
        return true;
    }
    unordered_map<node*,int> mp;
    node *temp=head;
    while(temp->next!=NULL){
        if(mp.find(temp)!=mp.end()){
            return true;
        }
        mp[temp]=1;
        temp=temp->next;
    }

    return false;
}