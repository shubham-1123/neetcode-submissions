#include <cstring>

class Solution {
public:
    int dp[101][101];
    int solve(string word1, string word2, int m, int n){
        if(m == 0)return n;
        if(n == 0)return m;
        if(dp[m][n]!= -1)return dp[m][n];
        if(word1[m-1] == word2[n-1])
            return dp[m][n] = solve(word1, word2, m-1, n-1);
        return dp[m][n] = 1 + min(min(solve(word1, word2, m, n-1), solve(word1, word2, m-1, n-1)), solve(word1, word2, m-1, n));
    }
    int minDistance(string word1, string word2) {
        memset(dp, -1, sizeof(dp));
        return solve(word1, word2, word1.size(), word2.size());
    }

};
