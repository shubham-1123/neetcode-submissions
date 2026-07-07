class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> cnt(256,0);
        int i = 0, j = 0;
        int maxLength = 0;
        while(j < s.size()){
            if(cnt[s[j]] == 0){
                cnt[s[j]] ++;
                maxLength = max(maxLength, j-i+1);
                j ++;
            }else{
                cnt[s[i]] --;
                i ++;
            }
        }
        return maxLength;
    }
};
