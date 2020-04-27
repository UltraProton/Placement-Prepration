class LRUCache {
public:
    //We are storing the key and address of the node in the queue in the map
    unordered_map<int,list<pair<int,int>>::iterator> mp;
    //The queue to store the nodes
    list<pair<int,int>> Q;
    int s;
    
    LRUCache(int capacity) {
        s=capacity;
    }
    
    int get(int key) {
        //key is present
        if(mp.find(key)!=mp.end()){
            int val=mp[key]->second;
            Q.erase(mp[key]);
            //make a new node to be inserted at the front with the same key and value as it is referenced least recently
            Q.push_front(make_pair(key,val));
            //update the reference of the key in the map
            mp[key]=Q.begin();
            return val;
        }
        else{
            return -1;
        }
    }
    
    void put(int key, int value) {
        //key is not present in the cache
        if(mp.find(key)==mp.end()){
            //check if the cache is full
            if(Q.size()==s){
                auto temp= Q.back(); //Note that here we will be given a pair
                //remove the last page 
                Q.pop_back();
                //remove the entry of the removed page from the map
                //? For erasing an entry from map we need only the key not reference
                mp.erase(temp.first);
            }
        }

        else{
            //If the key is already present then remove it from the queue
            //? The point to note here is that for erasing the node from the list we need an iterator to that node
            Q.erase(mp[key]);
        }

        //Make a new node to be pushed in the queue with the updated value
        Q.push_front(make_pair(key,value));
        //Update the reference in the map
        mp[key]=Q.begin();
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */