class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<pair<int,int>> dq;
        vector<int> ans;
        int i = 0;
        while(i < k){
            while(!dq.empty() && dq.back().first < nums[i])
                dq.pop_back();
            dq.push_back({nums[i],i});
            i ++ ;
        }

        ans.push_back(dq.front().first);
        i = 1;
        int j = k;

        while(j < nums.size()){
            while(!dq.empty() && dq.front().second < i)
                dq.pop_front() ;
            while(!dq.empty() && dq.back().first < nums[j])
                dq.pop_back();
            dq.push_back({nums[j], j});
            ans.push_back(dq.front().first);
            i ++ ;
            j ++ ;
        }
        return ans;
    }
};
