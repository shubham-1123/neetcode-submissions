class MyHashSet {
private:
    int maxSize;
    int hash(int key){
        return (key%maxSize);
    }
    std::vector<std::list<int>> set;
public:
    MyHashSet() {
        maxSize = 1000000;
        set.resize(maxSize);
    }
    
    void add(int key) {
        int idx = hash(key);
        for(auto& x: set[idx]){
            if(x == key)
                return ;
        }
        set[idx].push_back(key);
    }
    
    void remove(int key) {
        int idx = hash(key);
        
        for(auto it = set[idx].begin();it!=set[idx].end(); ++it){
            if(*it ==  key){
                set[idx].erase(it);
                return;
            }
        }
    }
    
    bool contains(int key) {
        int idx = hash(key);
        for(auto& x: set[idx]){
            if(x == key) return true;
        }
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */