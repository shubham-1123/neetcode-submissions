#include <cstring>

class Solution {
    int dp[1001][1001];
public:
    int helper(vector<int>& nums, int target, int n){
        if(n == 0)
            return (target == 0);
        if(dp[n][target]!=-1)
            return dp[n][target];

        int num = nums[n-1];
        int add = helper(nums, target+num, n-1);
        int sub = helper(nums, target-num, n-1);
        return dp[n][target] = add + sub;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        memset(dp, -1, sizeof(dp));
        return helper(nums, target, nums.size());
    }
};
