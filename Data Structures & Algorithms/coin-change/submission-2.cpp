#include <cstring>

class Solution {
    int dp[15][10001];
public:
    int helper(vector<int>& nums, int target, int n){
        if(target == 0)return 0;
        if(n == 0)
            return INT_MAX-1;
        if(dp[n][target]!=-1)
            return dp[n][target];
        if(nums[n-1]<=target)
            return dp[n][target] = min(1+helper(nums, target-nums[n-1], n), helper(nums, target, n-1));
        return dp[n][target] = helper(nums, target, n-1);
    }
    int coinChange(vector<int>& coins, int amount) {
        memset(dp, -1, sizeof(dp));
        int ways = helper(coins, amount, coins.size());
        if(ways >= INT_MAX-1)return -1;
        return  ways;
    }
};
