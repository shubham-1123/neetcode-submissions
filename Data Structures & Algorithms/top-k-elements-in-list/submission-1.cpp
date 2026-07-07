class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> result;
        unordered_map<int,int> mp;

        for(auto x: nums){
            mp[x] ++ ;
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq; // min priority queue

        for(auto x: mp){
            pq.push({x.second, x.first});
            if(pq.size() > k)
                pq.pop();
        }

        while(k!=0 && !pq.empty()){
            result.push_back(pq.top().second);
            pq.pop();
            k -- ;
        }

        return result;


    }
};
