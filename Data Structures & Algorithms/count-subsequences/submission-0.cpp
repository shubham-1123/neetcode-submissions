#include <cstring>
class Solution {
public:
    int dp[1001][1001];
    int solve(string s1, string s2, int m, int n){
        if(n == 0)return 1;
        if(m == 0) return 0;
        if(dp[m][n] != 0)return dp[m][n];
        if(s1[m-1] == s2[n-1])
            return dp[m][n] += (solve(s1,s2, m-1, n-1) +  solve(s1, s2, m-1, n));
        return dp[m][n] += solve(s1, s2, m-1, n);
    }
    int numDistinct(string s, string t) {
        memset(dp, 0, sizeof(dp));
        return solve(s, t, s.size(), t.size());
    }
};
