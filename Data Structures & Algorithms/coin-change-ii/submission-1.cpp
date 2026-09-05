#include <cstring>

class Solution {
    int dp[101][5001];
public:
    int helper(vector<int>& nums, int target, int n){
        if(target == 0) return 1;
        if(n == 0) return 0;
        if(dp[n][target]!=-1)return dp[n][target];
        int ans = 0;
        if(nums[n-1] <= target){
            ans += helper(nums, target-nums[n-1], n);
        }
        ans += helper(nums, target, n-1);
        return dp[n][target] = ans;
    }
    int change(int amount, vector<int>& coins) {
        memset(dp, -1, sizeof(dp));
        int ways = helper(coins, amount, coins.size());
        return ways;
    }
};
