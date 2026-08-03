class RandomizedSet {
    vector<int> vec;
    unordered_map<int,int> mp;
public:
    RandomizedSet() {
        vec.clear();
        mp.clear();
    }
    
    bool insert(int val) {
        if(mp.count(val))
            return false;
        int index = vec.size();
        vec.push_back(val);
        mp[val] = index;
        return true;
    }
    
    bool remove(int val) {
        if(mp.count(val)){
            int index = mp[val];
            int last_val = vec.back();
            
            vec[index] = last_val;
            mp[last_val] = index;
            
            vec.pop_back();
            mp.erase(val);
            return true;
        }
        return false;
    }
    
    int getRandom() {
        int random_index = rand() % vec.size();
        return vec[random_index];
    }
};