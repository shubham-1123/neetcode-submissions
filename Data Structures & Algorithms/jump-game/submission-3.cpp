class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size() == 1)return true;
        int jump = nums[0];
        for(int i=1;i<nums.size()-1;i++){
            if(jump >= nums.size()-1) return true;
            if(jump < i)return false;
            jump = max(jump, i+nums[i]);
        }
        return (jump >= nums.size()-1);
    }
};
