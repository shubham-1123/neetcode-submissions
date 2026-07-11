class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxLength = 0, count = 0;
        
        for(int i=0;i<nums.size();i++){
            if(nums[i] == 1){
                count ++;
            }else{
                maxLength = max(maxLength, count);
                count = 0;
            }
        }
        maxLength = max(maxLength, count);
        return maxLength;
    }
};