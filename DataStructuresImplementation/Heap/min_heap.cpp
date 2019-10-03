/* 

Operations: find(key), insert(key),  extractmin(), deletekey(), minheapify(), updatekey(), buildmaxheap() 

 */

#include<bits/stdc++.h>

using namespace std;

class min_heap{
    public:
    //data
    int heap_size;
    int storage_size;
    vector<int> Heap;

    //member functions
    min_heap(int n);
    int l_child(int idx);
    int r_child(int idx);
    int parent(int idx);
    void heap_insert_key(int key);
    int heap_extract_min();
    void min_heapify(int idx);
    void heap_update_key(int idx, int key);
    void print_heap();
    void build_max_heap();
    void heap_sort();
    void clrs_heap_sort();
    void insert_random_keys();
    //void heap_delete_key(int key);
};


int main(int argc, char const *argv[])
{
    min_heap obj(20);

    // obj.heap_insert_key(16);
    // obj.heap_insert_key(14);
    // obj.heap_insert_key(10);
    // obj.heap_insert_key(8);
    // obj.heap_insert_key(7);
    // obj.heap_insert_key(9);
    // obj.heap_insert_key(3);
    // obj.heap_insert_key(2);
    // obj.heap_insert_key(4);
    // obj.heap_insert_key(1);

    
    obj.insert_random_keys();
    //obj.print_heap();

    obj.build_max_heap();

    //obj.heap_update_key(4,0);
    // obj.print_heap();
    // char c='y';
    // while(c=='y'){
    //     obj.heap_extract_min();
    //     obj.print_heap();
    //     cin>>c;
    // }
    
    obj.print_heap();

    obj.clrs_heap_sort();

    obj.print_heap();


    cout<<endl;


    return 0;
}

// ************** this is more clear code ******************** 
void min_heap :: clrs_heap_sort(){
    build_max_heap();
    int n=heap_size;
    for(int i=n-1;i>0;i--){
        swap(Heap[i],Heap[0]);
        // * heap size has to decrease because we have swapped the last element with the first
        heap_size--;
        min_heapify(0);
    }
}


void min_heap :: heap_sort(){
    // ! always remember to build max heap before heapsort
    build_max_heap();
    int min_ele= INT_MAX;
    int n=heap_size;
    for(int i=0;i<n-1;i++){
        min_ele= heap_extract_min();
        // * because extract_min() decreases the size of the heap by one we have the index where we should put the min element
        Heap[heap_size]=min_ele;
    }
}


/* insert_random_keys() is just to test the build_min_heap()
 */

void min_heap :: insert_random_keys(){
    heap_size=Heap.size();
    for(int i=0;i<Heap.size();i++){
        Heap[i]= rand()%100;
    }
}

void min_heap :: build_max_heap(){
    int n=Heap.size()-1;
    for(int i=n/2; i>=0;i--){
        min_heapify(i);
    }
}

void min_heap :: print_heap(){
    for(auto x:Heap){
        cout<<x<<" ";
    }
    cout<<endl;
}

void min_heap :: heap_update_key(int idx, int key){
    Heap[idx]=key;
    while(idx>0 && Heap[parent(idx)] > Heap[idx] ){
        swap(Heap[parent(idx)], Heap[idx]);
        idx=parent(idx);
    }
}

min_heap :: min_heap(int n){
    heap_size=0;
    storage_size=n;
    Heap= vector<int>(n);
}

int min_heap::l_child(int idx){
    return (2*idx+1);
}

int min_heap::r_child(int idx){
    return (2*idx+2);
}

int min_heap :: parent(int idx){
    return (idx-1)/2;
}

void min_heap :: heap_insert_key(int key){
    Heap[heap_size] = key;
    heap_size++;

    int idx=heap_size-1;

    while(idx > 0 && Heap[parent(idx)] > Heap[idx]){
        swap(Heap[parent(idx)], Heap[idx]);
        idx=parent(idx);
    }
}

void min_heap :: min_heapify(int idx){
    if(idx>=heap_size){
        return;
    }

    int l_idx= l_child(idx);
    int r_idx= r_child(idx);
    int smallest= idx;

    if(l_idx < heap_size && Heap[l_idx] < Heap[smallest]){
        smallest= l_idx;
    }

    if(r_idx < heap_size && Heap[r_idx] < Heap[smallest]){
        smallest= r_idx;
    }

    if(smallest!=idx){
        swap(Heap[smallest], Heap[idx]);
        min_heapify(smallest);
    }
}

int min_heap:: heap_extract_min(){
    if(heap_size<1){
        cout<<"heap is empty"<<endl;
        return INT_MIN;
    }

    int ans= Heap[0];
    swap(Heap[0], Heap[heap_size-1]);
    Heap[heap_size-1]=INT_MAX;
    heap_size--;
    min_heapify(0);

    return ans;
}













