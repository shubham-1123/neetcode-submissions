class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";
        auto check = [](string& s1, string& s2){
            int  i = 0, j=0;
            while(i < s1.size() && j< s2.size()){
                if(s1[i] == s2[j]){
                    i ++, j++;
                }else
                    break;
            }
            return s1.substr(0, i);
        };
        ans = strs[0];
        for(int i=1;i<strs.size();i++){
            ans = check(strs[i], ans);
        }
        return ans;
    }
};