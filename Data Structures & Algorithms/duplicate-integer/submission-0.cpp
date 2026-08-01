class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> st;
        bool flag = false;
        for(auto x: nums){
            if(st.count(x))return true;
            else 
                st.insert(x);
        }
        return false;
    }
};