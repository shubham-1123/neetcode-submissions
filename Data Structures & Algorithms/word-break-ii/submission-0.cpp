class Solution {
    set<string> st;
    vector<string> result;
public:
    void helper(string s, int index, string curr){
        if(index == s.size()){
            result.push_back(curr);
            return;
        }
        for(int i=index;i<s.size();i++){
            string str = s.substr(index, i-index+1);
            if(st.count(str)){
                string temp = curr;
                if(temp!= ""){
                    temp += " ";
                }
                temp += str;
                helper(s, i+1, temp);
            }
        }
        return;
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        st = set<string>(wordDict.begin(), wordDict.end());
        helper(s, 0, "");
        return result;
    }
};