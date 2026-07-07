#include <cstring>
class Solution {
public:
    int dp[101];
    int rob(vector<int>& nums) {
        memset(dp, 0, sizeof(dp)) ;
        if(nums.size() == 1)
            return nums[0];
        
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]) ;

        if(nums.size() == 2)
            return dp[1] ;
        int maxProfit = INT_MIN;
        for(int i=2;i<nums.size();i++){
            dp[i] = max(dp[i-1], nums[i]+dp[i-2]) ;
            maxProfit = max(maxProfit, dp[i]) ;
        }

        return maxProfit;
        
    }
};
