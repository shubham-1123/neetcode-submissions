class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size()==1) return true;
        if(nums[0] == 0)return false;

        int jump = nums[0];
        for(int i=1;i<nums.size()-1;i++){
            if(jump < i) return false;
            if(jump >= nums.size()-1)return true;
            jump = max(jump, i+nums[i]);
        }
        return (jump < nums.size()-1)?false:true;
    }
};
