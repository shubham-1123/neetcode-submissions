class FreqStack {
public:
    int maxfreq = 0 ;
    unordered_map<int,int> frequency;
    unordered_map<int,vector<int>> group;
    FreqStack() {
        frequency.clear();
        group.clear();
    }
    
    void push(int val) {
        int f = ++frequency[val];
        maxfreq = max(maxfreq, f);
        group[f].insert(group[f].begin(), val);
    }
    
    int pop() {
        int val = group[maxfreq][0];
        frequency[val]--;
        group[maxfreq].erase(group[maxfreq].begin());
        if(group[maxfreq].size() == 0){
            group.erase(maxfreq);
            maxfreq --;
        }
        return val ;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */