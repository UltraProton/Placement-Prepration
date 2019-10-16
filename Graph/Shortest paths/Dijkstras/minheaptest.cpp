#include<bits/stdc++.h>

using namespace std;

// This node will be used in queue
class queue_node{
    public:
    int key; // The node identifier
    int distance; // The shortest distance of the node from the source
    queue_node(){}; //! Default constructor is important because when we are giving memory to vector<queue_node> storage in the 
                    //! Priority queue default constructor will be called
    queue_node(int k, int d);
};



class Priority_Queue{
    public:
    int queue_size;
    vector<queue_node> storage;
    vector<int> key_index; //* stores the index of key in the storage[] of priority queue
    queue_node extract_min();
    bool empty();
    int l_child(int idx);
    int r_child(int idx);
    int parent(int idx);
    void decrease_key(int idx, int key);
    void insert_key(int k, int d);
    void min_heapify(int idx);
    Priority_Queue();
};


int main(int argc, char const *argv[])
{
    /* code */
    Priority_Queue Q;
    Q.insert_key(1,2);
    Q.insert_key(5,0);
    Q.insert_key(3,4);
    Q.insert_key(4,7);
    Q.insert_key(2,5);
    Q.insert_key(0,6);

    for(int i=0;i<=5;i++){
        cout<<Q.key_index[i]<<endl;
    }


    return 0;
}




Priority_Queue :: Priority_Queue(){
    queue_size=0;
    // Giving the max size to queue
    storage= vector<queue_node>(1000);
    key_index= vector<int>(1000,-1);
}

bool Priority_Queue :: empty(){
    return queue_size==0;
}

void Priority_Queue :: insert_key(int k , int d){
    storage[queue_size]=queue_node(k,d);
    key_index[k]= queue_size;
    queue_size++;
    int idx=queue_size-1;
    while(idx > 0 && storage[idx].distance < storage[parent(idx)].distance){
        swap(key_index[storage[idx].key], key_index[storage[parent(idx)].key]);
        swap(storage[idx], storage[parent(idx)]);
        idx=parent(idx);
    }
}

void Priority_Queue :: decrease_key(int idx, int dist){
    storage[idx].distance=dist;
    while (idx > 0 && storage[idx].distance < storage[parent(idx)].distance)
    {

        swap(key_index[storage[idx].key], key_index[storage[parent(idx)].key]);
        
        swap(storage[idx], storage[parent(idx)]);

        idx=parent(idx);
    }
}

queue_node Priority_Queue :: extract_min(){
    
    if(queue_size==0){
        cout<<"Queue is empty"<<endl;
        return queue_node(-1,-1);
    }


    queue_node ans= storage[0];
    swap(key_index[storage[0].key], key_index[storage[queue_size-1].key]);
    key_index[storage[0].key]=-1;
    swap(storage[0], storage[queue_size-1]);
    queue_size--;
    min_heapify(0);

    return ans;
}

void Priority_Queue :: min_heapify(int idx){
    int l_idx= l_child(idx);
    int r_idx= r_child(idx);
    int smallest_idx= idx;

    if(l_idx < queue_size && storage[l_idx].distance < storage[smallest_idx].distance){
        smallest_idx=l_idx;
    }

    if(r_idx < queue_size && storage[r_idx].distance < storage[smallest_idx].distance){
        smallest_idx=r_idx;
    }

    if(smallest_idx != idx){

        swap(key_index[storage[smallest_idx].key], key_index[storage[idx].key]);
        swap(storage[smallest_idx], storage[idx]);
        min_heapify(smallest_idx);
    }
}

int Priority_Queue :: l_child(int idx){
    return (2*idx+1);
}

int Priority_Queue :: r_child(int idx){
    return (2*idx+2);
}

int Priority_Queue :: parent(int idx){
    return (idx-1)/2;
}


queue_node::queue_node(int k, int d){
    key=k;
    distance=d;
}
