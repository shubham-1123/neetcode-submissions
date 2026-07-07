// #include <cstring>
// class Solution {
// public:
//     int dp[1001][1001];
//     int solve(string s1, string s2, int m, int n){
//         if(n == 0)return 1;
//         if(m == 0) return 0;
//         if(dp[m][n] != 0)return dp[m][n];
//         if(s1[m-1] == s2[n-1])
//             return dp[m][n] += (solve(s1,s2, m-1, n-1) +  solve(s1, s2, m-1, n));
//         return dp[m][n] += solve(s1, s2, m-1, n);
//     }
//     int numDistinct(string s, string t) {
//         memset(dp, 0, sizeof(dp));
//         return solve(s, t, s.size(), t.size());
//     }
// };



class Solution {
public:
    // int dp[1001][1001];
    // int solve(string s, string t, int m, int n){
    //     if(n == 0)return 1;
    //     if(m == 0)return 0;
    //     if(dp[m][n]!=0)return dp[m][n];
    //     if(s[m-1] == t[n-1]){
    //         return dp[m][n] += (solve(s, t, m-1, n-1) + solve(s, t, m-1, n));
    //     }
    //     return dp[m][n] = solve(s, t, m-1, n);
    // }
    int numDistinct(string s, string t) {
        int m = s.size(), n = t.size();
        vector<vector<unsigned long long>> dp(m+1, vector<unsigned long long>(n+1, 0));
        for(int i=0;i<=m;i++){
            dp[i][0] = 1;
        }
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(s[i-1] == t[j-1]){
                    dp[i][j] += (dp[i-1][j-1] + dp[i-1][j]);
                }else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[m][n];
    }
};