class Solution {
public:
    bool binarySearch(vector<int>& nums, int mid, int k){
        int count = 0, sum = 0;
        for(int i=0;i<nums.size();i++){
            sum += nums[i];
            if(sum > mid){
                count ++ ;
                sum = nums[i];
            }
        }
        if(sum <= mid)
            count ++ ;
        return (count <= k);
    }
    int splitArray(vector<int>& nums, int k) {
        int left = *max_element(nums.begin(), nums.end());
        int right = accumulate(nums.begin(), nums.end(), 0);
        int ans = 0 ;
        while(left <= right){
            int mid = (left + right)/2;
            if(binarySearch(nums, mid, k)){
                ans = mid ;
                right = mid - 1;
            }else{
                left = mid + 1;
            }
        }
        return ans; 
    }
};