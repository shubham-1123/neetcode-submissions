class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size() == 1)return nums[0];
        int maxSum = nums[0], currSum = nums[0];
        for(int i=1;i<nums.size();i++){
            currSum = max(nums[i], currSum + nums[i]);
            maxSum = max(maxSum, currSum);
        }
        return maxSum;
    }
};
