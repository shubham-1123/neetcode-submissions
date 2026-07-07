class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() <= 1) return nums.size();
        unordered_set<int> st(nums.begin(), nums.end());

        int maxlen = 1;
        for(int i=0;i<nums.size();i++){
            int val = nums[i];
            if(st.find(val-1) == st.end()){
                int count = 0;
                while(st.find(val)!=st.end()){
                    val = val + 1;
                    count ++;
                }
                maxlen = max(maxlen, count);
            }
        }
        return maxlen;
    }
};
