#include <cstring> 

class Solution {
public:
    int dp[501][501];
    bool solve(vector<int>& piles, int i, int j, int alice, int bob, bool flag){
        if(i > j) return (alice > bob);

        if(dp[i][j]!=-1) return dp[i][j];

        if(flag){
           return dp[i][j] = solve(piles, i+1, j, alice + piles[i], bob, ~flag) || solve(piles, i, j-1, alice + piles[j], bob, ~flag);
        }
        return dp[i][j] = solve(piles, i+1, j, alice, bob + piles[i], ~flag) || solve(piles, i, j-1, alice, bob + piles[j], ~flag);
    }
    bool stoneGame(vector<int>& piles) {
        memset(dp, -1, sizeof(dp));
        return solve(piles, 0, piles.size()-1, 0, 0, true);
    }
};