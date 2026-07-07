#include <cstring>
class Solution {
public:
    int dp[35];
    int climbStairs(int n) {
        memset(dp, 0, sizeof(dp)) ;
        dp[1] = 1;
        dp[2] = 2;
        if(n < 3)
            return dp[n];

        for(int i=3;i<=n;i++){
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n] ;
    }
};
