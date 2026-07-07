// #include <deque>

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<pair<int,int>> dq;
        vector<int> result;
        int i = 0;
        while(i < k){
            while(!dq.empty() && dq.back().first <= nums[i])
                dq.pop_back();
            dq.push_back({nums[i], i});
            i ++ ;
        }
        result.push_back(dq.front().first);
        int j = 0;
        while(i < nums.size()){
            auto x = dq.front();
            if(x.second == j){
                dq.pop_front();
            }
            j ++ ;
            while(!dq.empty() && dq.back().first <= nums[i])
                dq.pop_back();
            dq.push_back({nums[i], i});
            result.push_back(dq.front().first);
            i ++ ;
        }
        return result;
    }
};
