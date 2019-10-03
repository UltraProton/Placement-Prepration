#include<bits/stdc++.h>

using namespace std;

typedef struct node{
    int key;
    int val;
    node *left;
    node *right;

    node(int k,int v): key(k), val(v),left(NULL), right(NULL) {};

} Node;

class LRU_Cache{
    public:
    Node *dummy_head;
    Node *dummy_tail;
    int size;
    int curr_size;
    unordered_map<int,Node *> mp;

    LRU_Cache(int size){
        this->size=size;
        curr_size=0;
        dummy_head= new Node(-1,-1);
        dummy_tail= new Node(-1,-1);
        dummy_head->left=NULL;
        dummy_tail->right=NULL;
        dummy_head->right=dummy_tail;
        dummy_tail->left=dummy_head;
    }

    void set(int key,int val);
    int get(int key);
    void push_front(Node *x);
    void remove(Node *x);
    void pop_last();
};

void LRU_Cache:: set(int key,int val){   
    if(mp.find(key)==mp.end()){
        Node *temp= new Node(key,val);
        //if cache is full remove the last element
        if(curr_size==size){
            pop_last();
            curr_size--;
        }
        push_front(temp);
        mp.insert(make_pair(key,temp));
        curr_size++;
    }
    else{
        mp[key]->val=val;
        remove(mp[key]);
        push_front(mp[key]);
    }   
}

int LRU_Cache:: get(int key){
    if(mp.find(key)==mp.end()){
        return -1;
    }
    else{
        remove(mp[key]);
        push_front(mp[key]);
        return mp[key]->val;
    }
}

void LRU_Cache :: push_front(Node *x){
    x->right= dummy_head->right;
    x->left=dummy_head;
    dummy_head->right=x;
    x->right->left= x;
}

void LRU_Cache :: remove(Node *x){
    x->left->right=x->right;
    x->right->left= x->left;

    x->left=NULL;
    x->right=NULL;
}

void LRU_Cache :: pop_last(){
    //assert(dummy_tail->left);
    Node *temp= dummy_tail->left;
    temp->left->right=dummy_tail;
    dummy_tail->left= temp->left;
    //cout<<'x'<<" ";
    mp.erase(temp->key);
    free(temp);
}



int main(int argc, char const *argv[])
{   
    LRU_Cache obj(2);

/*    
    obj.set(1,2);
    //cout<<obj.get(1)<<" "<<obj.curr_size<<endl;
    
    obj.set(2,3);
    //cout<<obj.get(2)<<" "<<obj.curr_size<<endl;
    
    obj.set(7,5);
    //cout<<obj.get(1)<<" "<<obj.curr_size<<endl;
    Node *l= obj.dummy_head;
    //cout<<l->key<<endl;
    //cout<<l->right->key<<endl;
    while(l->right!=NULL){
        cout<<l->key<<" ";
        l=l->right;
    }
    cout<<endl;
    
    obj.set(9,10);
    obj.set(11,12);
    obj.set(13,14);
    cout<<obj.get(7)<<" "<<obj.curr_size<<endl;
    cout<<obj.get(2)<<" "<<obj.curr_size<<endl;

    l= obj.dummy_head;
    //cout<<l->key<<endl;
    //cout<<l->right->key<<endl;
    while(l->right!=NULL){
        cout<<l->key<<" ";
        l=l->right;
    }
    cout<<endl;
    
   
/*
    Node *l= obj.dummy_head;
    cout<<l->key<<endl;
    //cout<<l->right->key<<endl;
    while(l->right!=NULL){
        cout<<l->key<<" ";
        l=l->right;
    }

    obj.set(7,9);
    cout<<obj.get(7)<<" "<<obj.curr_size<<endl;
    
*/    
    /*
    obj.set(1,5);
    obj.set(4,5);
    obj.set(6,7);
    cout<<obj.get(4)<<endl;
    cout<<obj.get(1)<<endl;

    */

   //SET 1 2 SET 2 3 SET 1 5 SET 4 5 SET 6 7 GET 4 GET 1
   //SET 1 2 SET 2 3 SET 1 5 SET 4 5 SET 6 7 GET 4 GET 1
  /*
    obj.set(1,2);
     
    obj.set(2,3);
    obj.set(1,5);
   
    obj.set(4,5);
    obj.set(6,7);
   
    cout<<obj.get(4)<<endl;
    cout<<obj.get(1)<<endl;

    Node *l= obj.dummy_head;
    //cout<<l->key<<endl;
    //cout<<l->right->key<<endl;
    while(l->right!=NULL){
        cout<<l->key<<" ";
        l=l->right;
    }

*/

//1
//GET 100 GET 26 GET 91 SET 55 40 GET 70 GET 43 GET 98 SET 5 56 GET 12 
/*
LRU_Cache obj1(1);

cout<<obj1.get(100)<<endl;
cout<< obj1.get(26)<<endl;
cout<<obj1.get(91)<<endl;
obj1.set(55,40);
cout<<obj1.get(70)<<endl;
cout<<obj1.get(43)<<endl;
cout<<obj1.get(98)<<endl;
obj1.set(5,56);
cout<<obj1.get(12)<<endl;
cout<<obj1.get(29)<<endl;

cout<<obj1.dummy_head->right->key<<endl;
*/

LRU_Cache obj2(2);
//S 2 1 S 1 1 S 2 3 S 4 1 G 1 G 2
obj2.set(2,1);
obj2.set(1,1);
obj2.set(2,3);
obj2.set(4,1);
cout<<obj2.get(1)<<endl;
cout<<obj2.get(2)<<endl;


return 0;
}
