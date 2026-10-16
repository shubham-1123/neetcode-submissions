#include <cstring>

class Solution {
    int dp[101];
public:
    int rob(vector<int>& nums) {
        memset(dp, 0, sizeof(dp));
        int n = nums.size();
        if(n == 1)return nums[0];
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        
        for(int i=2;i<n;i++){
            dp[i] = max(dp[i-2]+nums[i], dp[i-1]);
            // std::cout << dp[i] << " ";
        }
        int maxProfit = 0;
        for(int i=0;i<n;i++){
            maxProfit = max(maxProfit, dp[i]);
        }
        return maxProfit;
    }
};
