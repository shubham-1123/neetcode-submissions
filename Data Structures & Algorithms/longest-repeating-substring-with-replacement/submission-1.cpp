class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<int,int> mp;
        int maxLength = 0, l = 0;
        int maxSofar = 0;
        for(int r=0;r<s.size();r++){
            mp[s[r]] ++;
            maxSofar = max(maxSofar, mp[s[r]]);

            if((r-l+1)-maxSofar > k){
                mp[s[l]] --;
                l ++;
            }
            maxLength = max(maxLength, r-l+1);
        }
        return maxLength; 
    }
};
