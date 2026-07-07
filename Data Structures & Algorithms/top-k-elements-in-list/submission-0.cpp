class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp ;
        vector<int> result;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]] ++ ;
        }
        priority_queue<pair<int,int>> pq;
        for(auto x : mp){
            pq.push({x.second, x.first});
        }
        while(!pq.empty() && k!=0){
            pair<int,int> pr = pq.top();
            pq.pop();
            result.push_back(pr.second);
            k --;
        }
        return result ;
    }
};
