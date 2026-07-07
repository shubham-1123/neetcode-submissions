class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result ;
        unordered_map<string, vector<string>> mp;

        if(strs.size() <= 1){
            result.push_back(strs);
            return result;
        }

        for(int i=0; i<strs.size(); i++){
            string temp = strs[i];
            sort(temp.begin(), temp.end());
            mp[temp].push_back(strs[i]);
        }

        for(auto x: mp){
            result.push_back(x.second);
        }
        return result;

    }
};
