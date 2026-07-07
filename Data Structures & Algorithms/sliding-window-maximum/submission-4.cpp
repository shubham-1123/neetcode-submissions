class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if(k == 1)return nums;
        vector<int> result;
        deque<pair<int,int>> dq;

        int i = 0;
        while(i < k){
            while(!dq.empty()){
                if(dq.back().first <= nums[i])
                    dq.pop_back();
                else 
                    break;
            }
            dq.push_back({nums[i], i});
            i ++;
        }
        result.push_back(dq.front().first);
        int left = 0;
        for(;i<nums.size();i++){
            auto x = dq.front();

            if(x.second == left){
                dq.pop_front();
            }
            left ++;
            while(!dq.empty() && dq.back().first <= nums[i])
                dq.pop_back();
            dq.push_back({nums[i], i});
            result.push_back(dq.front().first);
        }
        return result;
    }
};
