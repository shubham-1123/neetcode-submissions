class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        vector<int> cnt(26, 0);
        
        for(char x: s){
            cnt[x-'a'] ++ ;
        }
        for(char x: t){
            cnt[x-'a'] --;
        }
        for(int i=0;i<26;i++){
            if(cnt[i]!=0)return false;
        }
        return true;
    }
};
