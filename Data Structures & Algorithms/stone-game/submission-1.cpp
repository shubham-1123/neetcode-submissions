#include <cstring>

class Solution {
    int dp[501][501];
public:
    bool helper(vector<int>& piles, int i, int j, int alice, int bob, bool flag){
        if(i > j)
            return alice > bob;
        if(dp[i][j]!=0)return dp[i][j];
        if(flag)
            return dp[i][j] = helper(piles, i+1, j, alice+piles[i], bob, ~flag) || helper(piles, i, j-1, alice+piles[j], bob, ~flag);
        return dp[i][j] = helper(piles, i+1, j, alice, bob+piles[i], ~flag) || helper(piles, i, j-1, alice, bob+piles[j], ~flag);
    }
    bool stoneGame(vector<int>& piles) {
        memset(dp, 0, sizeof(dp));
        return helper(piles, 0, piles.size()-1, 0, 0, true);
    }
};