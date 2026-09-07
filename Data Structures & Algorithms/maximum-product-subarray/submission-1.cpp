class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int curMin = nums[0], curMax = nums[0], maxVal = nums[0];
        for(int i=1;i<nums.size();i++){
            int temp = max({nums[i], curMin*nums[i], curMax*nums[i]});
            curMin = min({nums[i], curMin*nums[i], curMax*nums[i]});
            curMax = max(curMin, temp);
            maxVal = max(curMax, maxVal);
        }
        return maxVal;
    }
};
