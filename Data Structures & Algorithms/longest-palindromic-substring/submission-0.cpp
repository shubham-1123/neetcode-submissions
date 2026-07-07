#include <cstring>
class Solution {
public:
    int dp[1001][1001];
    string longestPalindrome(string s) {
        string res = "";
        int n = s.size();
        memset(dp, 0, sizeof(dp));

        res = res + s[0];
        int length = 1;
        for(int i=0;i<n;i++){
            dp[i][i] = 1;
        }

        for(int i=0;i<n-1;i++){
            if(s[i] == s[i+1]){
                dp[i][i+1] = 1;
                if(length < 2){
                    res.clear() ;
                    res += s.substr(i, 2);
                }
            }
        }

        for(int gap=2;gap<n;gap++){
            for(int i=0;i+gap<n;i++){
                int j = i + gap ;
                int d = (j-i+1) ;
                if(s[i] == s[j] && dp[i+1][j-1] == 1){
                    if(length < d){
                        length = d;
                        res.clear() ;
                        res += s.substr(i, d);
                    }
                    dp[i][j] = 1;
                }
            }
        }

        return res;
    }
};
