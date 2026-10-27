class LRUCache {
    private:
    int capacity;
    list<pair<int, int>> dll; // {key, value}
    unordered_map<int, list<pair<int, int>>::iterator> mp;
public:
    LRUCache(int capacity) {
         this->capacity = capacity;
    }
    
    int get(int key) {
          if (mp.find(key) == mp.end()) {
            return -1;
        }

        auto it = mp[key];

        // Move recently accessed key to the front
        dll.splice(dll.begin(), dll, it);

        return it->second;
    }
    
    void put(int key, int value) {
        if (capacity == 0) return;

        // Key already exists: update and mark as recently used
        if (mp.find(key) != mp.end()) {
            auto it = mp[key];
            it->second = value;
            dll.splice(dll.begin(), dll, it);
            return;
        }

        // Cache is full: remove least recently used key
        if (dll.size() == capacity) {
            auto lru = dll.back();
            mp.erase(lru.first);
            dll.pop_back();
        }

        // Insert new key at the front
        dll.push_front({key, value});
        mp[key] = dll.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */