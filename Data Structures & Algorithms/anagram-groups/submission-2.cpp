class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        unordered_map<string, vector<string>> mp;

        if(strs.size() <= 1){
            result.push_back(strs);
            return result;
        }

        for(auto &x : strs){
           vector<int> cnt(26, 0);
            for(char c : x){
                cnt[c-'a'] ++;
            }
            string key = "" ;
            for(auto i : cnt){
                key += '#' + to_string(i);
            }
            mp[key].push_back(x);
        }

        for(auto x: mp){
            result.push_back(x.second);
        }
        return result;

    }
};
