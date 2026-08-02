class FreqStack {
    int maxFreq;
    unordered_map<int,int> frequency;
    unordered_map<int,vector<int>> group;
public:
    FreqStack() {
        maxFreq = 0;
        frequency.clear();
        group.clear();
    }
    
    void push(int val) {
        int f = ++frequency[val];
        maxFreq = max(maxFreq, f);
        group[f].insert(group[f].begin(), val);
    }
    
    int pop() {
        int val = group[maxFreq][0];
        frequency[val]--;
        group[maxFreq].erase(group[maxFreq].begin());
        if(group[maxFreq].size()==0){
            group.erase(maxFreq);
            maxFreq--;
        }
        return val;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */