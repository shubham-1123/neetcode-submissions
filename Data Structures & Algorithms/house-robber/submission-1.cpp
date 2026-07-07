#include <cstring>

class Solution {
    int arr[100];
public: 
    int rob(vector<int>& nums) {
        memset(arr, 0, sizeof(arr));
        if(nums.size() == 1)return nums[0];

        arr[0] = nums[0];
        arr[1] = max(nums[0], nums[1]);
        if(nums.size() == 2)return arr[1];

        int maxProfit = arr[1];
        for(int i=2;i<nums.size();i++){
            arr[i] = max(nums[i]+arr[i-2], arr[i-1]);
            maxProfit = max(maxProfit, arr[i]);
        }
        return maxProfit;
    }
};
