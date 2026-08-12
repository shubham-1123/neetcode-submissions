class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        if(n == 1) return false;

        unordered_map<int,int> mp;
        int curr_sum = 0;
        mp[0] = -1;

        for(int i=0;i<n;i++){
            curr_sum = (curr_sum + nums[i])%k;
            if(mp.count(curr_sum)){
                int diff = i - mp[curr_sum];
                if(diff >= 2) return true;
            }else
                mp[curr_sum] = i;
        }
        return false;
    }
};