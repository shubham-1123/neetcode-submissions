#include <cstring>
class Solution {
    int dp[1001][1001];
public:
    string longestPalindrome(string s) {
        if(s.size()  == 1)return s;
        memset(dp, 0, sizeof(dp));

        int n = s.size(), maxLen = 1;
        string result = "";
        result = s.substr(0, 1);

        for(int i=0;i<n;i++){
            dp[i][i] = 1;
        }
        for(int i=0;i<n-1;i++){
            if(s[i] == s[i+1]){
                dp[i][i+1] = 1;
                if(maxLen < 2){
                    maxLen=2;
                    result.clear();
                    result = s.substr(i, 2);
                }
            }
        }

        for(int gap=2;gap<n;gap++){
            for(int i=0;gap+i<n;i++){
                int j = i + gap;
                if(s[i] == s[j] && dp[i+1][j-1]==1){
                    dp[i][j] = 1;
                    int d = j-i+1;
                    if(maxLen < d){
                        maxLen = d;
                        result.clear();
                        result = s.substr(i, d);
                    }
                }
            }
        }
        return result;
    }
};
