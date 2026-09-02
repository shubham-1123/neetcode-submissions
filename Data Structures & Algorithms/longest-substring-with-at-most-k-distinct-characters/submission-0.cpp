class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        if(k == 0)return 0;

        vector<int> cnt(26, 0);
        int i =0, j = 0, count = 0;
        int maxLen = 0;
        while(i < s.size()){
            if(cnt[s[i]-'a'] == 0 || count <= k){
                cnt[s[i]-'a'] ++;
                if(cnt[s[i]-'a'] == 1)
                    count ++;
                if(count <= k)
                    maxLen = max(maxLen, i-j+1);
                // std::cout << i << " " << j <<  " " << count << " " << maxLen << '\n';
                i ++;
            }else{
                cnt[s[j]-'a']--;
                if(cnt[s[j]-'a'] == 0 && count > 0)
                    count --;
                j ++;
            }
        }
        return maxLen;
    }
};
