class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if(k == 1)return nums;
        vector<int> result;
        deque<pair<int,int>> dq;
        int i = 0;
        for(int i=0;i<k;i++){
            while(!dq.empty() && (nums[i] >= dq.back().first)){
                dq.pop_back();
            }
            dq.push_back({nums[i],i});
        }
        result.push_back(dq.front().first);
        int left = 0;
        for(i=k;i<nums.size();i++){
            auto x = dq.front();
            if(x.second == left){
                dq.pop_front();
            }
            while(!dq.empty() && (nums[i] >= dq.back().first)){
                dq.pop_back();
            }
            dq.push_back({nums[i],i});
            result.push_back(dq.front().first);
            left ++;
        }
        return result;
    }
};
