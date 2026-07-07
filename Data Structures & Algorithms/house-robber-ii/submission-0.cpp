class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
    
        if(n == 1)
            return nums[0] ;
        if(n == 2)
            return max(nums[0], nums[1]) ;
        
        vector<int> temp = nums;

        nums[1] = max(nums[0], nums[1]) ;
        int max1 = nums[1];
        for(int i=2;i<n-1;i++){
            nums[i] = max(nums[i]+nums[i-2], nums[i-1]) ;
            max1 = max(max1, nums[i]);
        }

        temp[2] = max(temp[1], temp[2]);
        int max2 = temp[2] ;

        for(int i=3;i<n;i++){
            temp[i] = max(temp[i]+temp[i-2], temp[i-1]) ;
            max2 = max(max2, temp[i]) ;
        }

        return max(max1, max2) ;
    }
};