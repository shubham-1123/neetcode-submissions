#include <cstring>

class Solution {
    int dp[101][1500];
public:
    bool helper(vector<int>& nums, int target, int n){
        if(target == 0) return true;
        if(n == 0) return false;
        if(dp[n][target]!= 0)
            return dp[n][target];
        if(nums[n-1] <= target) 
            return dp[n][target] = helper(nums, target-nums[n-1], n-1) || helper(nums, target, n-1);
        return dp[n][target] = helper(nums, target, n-1);
    }
    bool canPartition(vector<int>& nums) {
        int sum =0;
        for(auto x : nums)
            sum += x;
        if(sum%2)return false;
        memset(dp, 0, sizeof(dp));
        sum = sum/2;
        return helper(nums, sum, nums.size());
    }
};
