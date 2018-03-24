class LRUCache {
public:
    LRUCache(int capacity) {
        this->cap = capacity;
    }
    
    int get(int key) {
        int value = -1;
        if (!mp.count(key)) {
            return value; // error
        }
        value = mp[key]->second;
        l.erase(mp[key]);
        l.push_front(make_pair(key, value));
        mp[key] = l.begin();
        return value;
    }
    
    void put(int key, int value) {
        if (mp.count(key)) {
            l.erase(mp[key]);
        } else if (mp.size() == this->cap) {
            int key2rm = l.back().first;
            l.erase(mp[key2rm]);
            mp.erase(key2rm);
        }
        l.push_front(make_pair(key, value));
        mp[key] = l.begin();
    }
private:
    int cap;
    list<pair<int,int>> l;
    unordered_map<int, list<pair<int,int>>::iterator> mp;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
