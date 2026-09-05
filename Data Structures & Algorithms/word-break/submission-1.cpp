#include <cstring>
class Solution {
    set<string> st;
    int dp[201];
public:
    bool helper(string s, int index){
        if(index >= s.size())return 1;
        if(dp[index]!=-1)return dp[index];
        string str = "";
        for(int i=index;i<s.size();i++){
            str += s[i];
            if(st.count(str) && helper(s, i+1)){
                return dp[index] = 1;
            }
        }
        return dp[index] = 0;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        st = set<string>(wordDict.begin(), wordDict.end());
        memset(dp, -1, sizeof(dp));
        return helper(s, 0);
    }
};
