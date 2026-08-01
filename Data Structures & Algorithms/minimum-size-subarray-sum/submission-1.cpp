class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int curr_sum = 0;
        int i =0, j =0, minLength = INT_MAX;
        while(i < nums.size()){
            curr_sum += nums[i];
            while(curr_sum >= target){
                minLength = min(minLength, i-j+1);
                curr_sum -= nums[j++];
            }
            i ++;
        }
        return (minLength == INT_MAX)?0:minLength;
    }
};