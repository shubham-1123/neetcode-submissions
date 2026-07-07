class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() == 0) return 0;
        vector<int> cnt(256, 0) ;
        int i=0,j=0;
        int length = 1 ;
        while(j < s.size()){
            if(!cnt[s[j]]){
                cnt[s[j]] ++ ;
                length = max(length, j-i+1) ;
                j++;
            }else{
                cnt[s[i]] -- ;
                i++;
            }
        }
        return length;
    }
};
