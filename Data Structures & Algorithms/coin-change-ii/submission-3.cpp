#include <cstring>

class Solution {
    int dp[101][5001];
public:
    int helper(vector<int>& coins, int amount, int n){
        if(amount  == 0) return 1;
        if(n == 0) return 0;
        if(dp[n][amount]!=-1)return dp[n][amount];
        int ans = 0 ;
        if(coins[n-1] <= amount){
            ans += helper(coins, amount-coins[n-1], n);
        }
        ans += helper(coins, amount, n-1);
        return dp[n][amount] = ans;
    }
    int change(int amount, vector<int>& coins) {
        memset(dp, -1, sizeof(dp));
        int ways = helper(coins, amount, coins.size());
        return ways;
    }
};
