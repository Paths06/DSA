#include <list>
#include <unordered_map>
using namespace std;

class LRUCache {
private:
    int capacity;

    // Doubly linked list storing (key, value)
    list<pair<int,int>> cache;

    // key -> iterator pointing to node in list
    unordered_map<int, list<pair<int,int>>::iterator> mp;

public:

    LRUCache(int capacity) {
        this->capacity = capacity;
    }

    int get(int key) {

        // If key not present
        if (!mp.count(key))
            return -1;

        // Retrieve value
        int value = mp[key]->second;

        // Remove node from current position
        cache.erase(mp[key]);

        // Reinsert as most recently used
        cache.push_back({key, value});

        // Update iterator
        mp[key] = prev(cache.end());

        return value;
    }

    void put(int key, int value) {

        // If key already exists remove old node
        if (mp.count(key)) {
            cache.erase(mp[key]);
            mp.erase(key);
        }

        // If capacity reached remove LRU
        if (cache.size() == capacity) {

            // LRU element is at front
            int lruKey = cache.front().first;

            cache.pop_front();
            mp.erase(lruKey);
        }

        // Insert new node at MRU position
        cache.push_back({key, value});

        // Store iterator
        mp[key] = prev(cache.end());
    }
};
