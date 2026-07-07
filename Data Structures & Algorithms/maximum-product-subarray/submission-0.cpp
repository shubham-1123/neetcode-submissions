class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int curMin = nums[0], curMax = nums[0], maxVal=nums[0];

        for(int i=1;i<nums.size();i++){
            int temp = max({nums[i] , nums[i]*curMin, nums[i]*curMax}) ;
            curMin = min({nums[i] , nums[i]*curMin, nums[i]*curMax});
            curMax = max(curMin, temp) ;
            maxVal = max(maxVal, curMax);
        }
        return maxVal;
    }
};
