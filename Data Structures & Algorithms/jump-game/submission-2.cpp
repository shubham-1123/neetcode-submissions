class Solution {
public:
    bool canJump(vector<int>& nums) {
    
        int n = nums.size();
        if(n > 1){
            if(nums[0] == 0)return false;
        }
        int jump = 0;
        for(int i=0;i<n-1;i++){
            if(jump < i) return false;
            jump = max(jump, i + nums[i]);
            if(jump >= n-1) return true;
        }
        return (jump < n-1)?false:true;
    }
};
