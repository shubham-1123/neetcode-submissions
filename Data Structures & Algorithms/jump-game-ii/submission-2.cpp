class Solution {
public:
    int jump(vector<int>& nums) {
        
        if(nums.size() == 1)
            return 0;
        // if(nums.size() > 1){
        //     if(nums[0] == 0) return -1;
        // }
        int jmp = nums[0], temp = nums[0];
        int count = 1;
        for(int i=0;i<nums.size()-1;i++){
            jmp = max(nums[i]+i, jmp);

            if(i == temp){
                temp = jmp ;
                count ++ ;
            }
        }
        return count ;
    }
};
