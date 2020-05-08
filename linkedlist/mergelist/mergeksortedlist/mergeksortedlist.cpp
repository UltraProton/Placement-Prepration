#include<bits/stdc++.h>

using namespace std;

class ListNode {
    public:
    int val;
    ListNode *next;
    ListNode():val(0),next(nullptr){}
    ListNode(int val):val(val),next(NULL){}
    ListNode(int x, ListNode *node): val(x), next(node){}
};

class compare{
    bool operator()(const ListNode *a, const ListNode *b){
        return a->val > b->val;
    }
};


ListNode *mergekLists(vector<ListNode *> lists);

int main(){
    vector<ListNode *> lists;
    return 0;
}

ListNode *mergekLists(vector<ListNode *> lists){
    ListNode *result=NULL;
    ListNode *prev=NULL;
    priority_queue<ListNode *, vector<ListNode *> , compare> pq;
    int n=lists.size();
    for(int i=0;i<n;i++){
        pq.push(lists[i]);
    }
    ListNode *curr=NULL;
    while(!pq.empty()){
        curr=pq.top();;
        pq.pop();
        if(result==NULL){
            result=new ListNode(curr->val);
            prev=result;
        }
        else{
            prev->next= new ListNode(curr->val);
            prev=prev->next;
        }
        //This step is the most important. We should check for the next of the current removed from the 
        //priority queue and push that in the priority queue. This element will capture its correct position in
        //the priority queue.
        if(curr->next){
            pq.push(curr->next);
        }
    }

    return result;
}
