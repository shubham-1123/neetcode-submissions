class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int i = 0, j = 0, k = 0;
        int maxLen = 0;
        while(i < nums.size()){
            if(nums[i] == 1){
                maxLen = max(maxLen, i-j+1);
                i ++;
            }else if(k == 0){
                maxLen = max(maxLen, i-j+1);
                k ++ ;
                i ++;
            }else if(nums[i] == 0){
                if(nums[j] == 0)
                    k = 0;
                j ++;
            }
        }
        return maxLen;
    }
};
