class LRUCache {
    unordered_map<int, pair<int, list<int>::iterator>> cache;
    list<int> order;
    int capacity;
public:
    LRUCache(int capacity):capacity(capacity) {
        cache.clear();
        order.clear();
    }
    
    int get(int key) {
        if(cache.size()==0 || !cache.count(key))
            return -1; 
        order.erase(cache[key].second);
        order.push_back(key);
        cache[key].second = --order.end();
        return cache[key].first;
    }
    
    void put(int key, int value) {
        if(cache.count(key)){
            order.erase(cache[key].second);
            order.push_back(key);
            cache[key] = {value, --order.end()};
        }else{
            if(cache.size() == capacity){
                int k = order.front();
                order.pop_front();
                cache.erase(k);
            }
            order.push_back(key);
            cache[key] = {value,  --order.end()};
        }
    }
};
