#include <iostream>
#include <unordered_map>
#include <list>

using namespace std;

class LFUCache {
public:
    int capacity;
    int leastFreq;
    unordered_map<int, int> keyVal;
    unordered_map<int, int> keyFreq;
    unordered_map<int, list<int>> freqList;
    unordered_map<int, list<int>::iterator> keyIter;
    LFUCache(int capacity) {
        this->capacity = capacity;
        leastFreq = 0;
    }
    
    int get(int key) {
        if(!keyVal.count(key))return -1;
        int f = keyFreq[key];
        freqList[f].erase(keyIter[key]);

        if(freqList[f].empty() and leastFreq == f)
            leastFreq +=1;

        keyFreq[key] +=1;
        freqList[f+1].push_front(key);
        keyIter[key] = freqList[f+1].begin();
        return keyVal[key];
    }
    
    void put(int key, int value) {
        if(capacity == 0) return;
        if(keyVal.count(key)){
            keyVal[key] = value ;
            get(key);
            return ;
        }
        if(capacity == keyVal.size()){
            int k = freqList[leastFreq].back();
            freqList[leastFreq].pop_back();
            keyIter.erase(k);
            keyVal.erase(k);
            keyFreq.erase(k);
        }

        keyVal[key] = value;
        keyFreq[key] = 1;
        freqList[1].push_front(key);
        keyIter[key] = freqList[1].begin();
        leastFreq = 1;
        return;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */