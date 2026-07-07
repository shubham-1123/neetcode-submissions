class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size(), i=0;
        while(i < n){
            while((nums[i] > 0 && nums[i] <= n) && (nums[i] != i+1) && (nums[i] != nums[nums[i]-1]) ){
                swap(nums[i], nums[nums[i]-1]);
            }
            i++;
        }
        int ans = 1;
        for(i=0;i<n;i++){
            if(nums[i] != i+1){
                ans = i+1;
                break;
            }
        }
        return (i >= n)?n+1:ans;
    }
};