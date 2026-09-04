#include <cstring>

class Solution {
    int dp[101][101];
public:
    int helper(string& word1, string& word2, int m, int n){
        if(m == 0 && n == 0)return 0;
        if(m == 0) return n;
        if(n == 0) return m;

        if(dp[m][n] != -1)
            return dp[m][n];
       
        if(word1[m-1] == word2[n-1])
            return dp[m][n] = helper(word1, word2, m-1, n-1);
        return dp[m][n] = 1+ min(min(helper(word1, word2, m, n-1), helper(word1, word2, m-1, n)), helper(word1, word2, m-1, n-1));
    }
    int minDistance(string word1, string word2) {
        memset(dp, -1, sizeof(dp));
        return helper(word1, word2, word1.size(), word2.size());
    }
};
