#include <cstring>
class Solution {
public:
    int dp[1001][1001];
    int helper(string& st1, string& st2, int m, int n){
        if(m == 0 || n == 0) return 0;
        if(dp[m-1][n-1] != -1)
            return dp[m-1][n-1];
        if(st1[m-1] == st2[n-1])
            return dp[m-1][n-1] = 1 + helper(st1, st2, m-1, n-1);
        return dp[m-1][n-1] = max(helper(st1, st2, m-1, n), helper(st1, st2, m, n-1));
    }
    int longestCommonSubsequence(string text1, string text2) {
        memset(dp, -1, sizeof(dp));
        int m = text1.size(), n = text2.size();
        int length = helper(text1, text2, m, n);
        return length;
    }
};
