class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int currSum = 0, left = 0, right = 0;
        int minLength = INT_MAX;

        while(right < nums.size()){
            currSum += nums[right];
            while(currSum >= target){
               minLength = min(minLength, right-left+1);
               currSum -= nums[left++]; 
            }
            right++;
        }
        return (minLength == INT_MAX)?0:minLength;
    }
};