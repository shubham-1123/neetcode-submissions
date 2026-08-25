class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int l = *max_element(nums.begin(), nums.end());
        int r = accumulate(nums.begin(), nums.end(), 0);
        int largestSum = 0;

        auto helper = [&](int mid){
            int sum =0, count =0;
            for(int i=0;i<nums.size();i++){
                sum += nums[i];
                if(sum > mid){
                    count ++;
                    sum = nums[i];
                }
            }
            if(sum <= mid)
                count ++;
            return (count <= k);
        };

        while(l <= r){
            int m = l + (r-l)/2 ;
            if(helper(m)){
                largestSum = m;
                r = m -1;
            }else   
                l = m + 1;
        }
        return largestSum;
    }
};