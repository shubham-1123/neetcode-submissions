class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() <= 1)return nums.size();
        unordered_set<int> st(nums.begin(), nums.end());
        int longest = 0;

        for(int i=0;i<nums.size();i++){
            int x = nums[i]-1;
            if(!st.count(x)){
                int len = 0;
                x = x + 1;
                while(st.count(x)){
                    len ++ ;
                    x = x + 1;
                }
                longest = max(longest, len);
            }
        }
        return (longest ==0)?1:longest;
    }
};
