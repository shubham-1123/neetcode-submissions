class LRUCache {
public:
    int capacity;
    list<int> order;
    unordered_map<int, pair<int, list<int>::iterator>> lruCache;
    LRUCache(int capacity):capacity(capacity) {
        order.clear();
        lruCache.clear();
    }

    int get(int key) {
        if(!lruCache.count(key)){
            return -1;
        }
        order.erase(lruCache[key].second);
        order.push_back(key);
        lruCache[key].second = --order.end();
        return lruCache[key].first;
    }
    
    void put(int key, int value) {

        if(lruCache.count(key)){
            order.erase(lruCache[key].second);
            order.push_back(key);
            lruCache[key] = {value, --order.end()};
        }else{
            if(lruCache.size() == capacity){
                int k = order.front();
                order.pop_front();
                lruCache.erase(k);
            }
            order.push_back(key);
            lruCache[key] = {value, --order.end()};
        }


    }
};
