// class MyHashMap {
// public:
//     MyHashMap() {
        
//     }
    
//     void put(int key, int value) {
        
//     }
    
//     int get(int key) {
        
//     }
    
//     void remove(int key) {
        
//     }
// };



class MyHashMap {
private:
    int maxSize;
    struct Pair{
        int key, value;
        Pair(int key, int value):key(key),value(value){}
    };
    int hashValue(int key){
        return (key%maxSize);
    }
    std::vector<std::list<Pair>> map;
public:
    MyHashMap() {
        maxSize = 1000000;
        map.resize(maxSize);
    }
    
    void put(int key, int value) {
        int idx = hashValue(key);
        for(auto& x : map[idx]){
            if(x.key == key){
                x.value = value;
                return;
            }
        }
        map[idx].push_back(Pair(key, value));
    }
    
    int get(int key) {
        int idx = hashValue(key);
        for(auto& x: map[idx]){
            if(x.key == key){
                return x.value; 
            }
        }
        return -1;
    }
    
    void remove(int key) {
        int idx = hashValue(key);
        for(auto it = map[key].begin(); it!= map[key].end(); ++it){
            if(it->key == key){
                map[key].erase(it);
                return;
            }
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */