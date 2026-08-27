class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        if(nums.size() == 1)return;
        int index = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i] != 0){
                nums[index++] = nums[i];
                // nums[i] = 0;
            }
        }
        for(;index<nums.size();index++)
            nums[index] = 0;
        return ;
    }
};