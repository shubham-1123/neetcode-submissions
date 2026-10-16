class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int left = *max_element(weights.begin(), weights.end());
        int right = accumulate(weights.begin(), weights.end(), 0);
        // std::cout << left << " " << right << endl;
        auto helper = [](vector<int>& nums, int mid, int d){
            int counter = 0, sum=0 ;
            for(int i=0;i<nums.size();i++){
                sum += nums[i];
                if(sum > mid){
                    counter ++ ;
                    sum = nums[i];
                }
            }
            counter ++ ;
            return(counter <= d);
        };
        int capacity = 0;
        while(left <= right){
            int mid = left + (right-left)/2;
            if(helper(weights, mid, days)){
                capacity = mid;
                right = mid -1;
            }else
                left = mid + 1;
        }
        return capacity;
    }
};