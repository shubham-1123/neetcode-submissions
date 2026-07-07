#include <cstring>

class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int totalSum = 0;
        for(int i=0;i<stones.size();i++)
            totalSum+= stones[i];
        int n = totalSum/2;
        bool dp[n+1];
        memset(dp, false, sizeof(dp));
        dp[0] = true;
        for(auto stone : stones){
            for(int i=n;i>=stone;i--){
                dp[i] = (dp[i] || dp[i-stone]);
            }
        }

        for(int i=n;i>=0;i--){
            if(dp[i])
                return totalSum -2*i;
        }
        return 0;
    }
};