class LRUCache {
public:
    int size;
    list<pair<int, int>> lst; //list of key, value
    unordered_map<int, list<pair<int, int>>::iterator> cache; //hashmap of key + list
    LRUCache(int capacity) {
        size = capacity;
    }
    
    int get(int key) {
        auto it = cache.find(key);
        if(it == cache.end()) return -1;
        lst.splice(lst.begin(),lst, cache[key]);
        return cache[key]->second;
    }
    
    void put(int key, int value) {
        if(cache.find(key)!= cache.end()){
            lst.splice(lst.begin(), lst, cache[key]);
            cache[key]->second = value;
            return;
        }
        if(lst.size() == size){
            auto delete_key = lst.back().first;
            lst.pop_back();
            cache.erase(delete_key);
        }
        lst.push_front({key,value});
        cache[key]=lst.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
