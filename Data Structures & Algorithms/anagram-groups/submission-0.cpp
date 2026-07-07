class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        unordered_map<string, vector<string>> mp ;
        for(int i=0;i<strs.size();i++){
            string str = strs[i];
            sort(strs[i].begin(), strs[i].end());
            mp[strs[i]].push_back(str);
        }
        for(auto x : mp){
            auto ptr = x.second;
            vector<string> v;
            for(auto t : ptr){
                v.push_back(t);
            }
            result.push_back(v);
        }
        return result ;
    }
};
