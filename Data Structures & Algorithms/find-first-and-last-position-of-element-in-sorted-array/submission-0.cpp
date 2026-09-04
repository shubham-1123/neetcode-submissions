class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result;
        auto leftPos = [](vector<int>& nums, int target){
            int left = 0, right = nums.size()-1;
            int ans = -1;
            while(left <= right){
                int mid = left + (right-left)/2;
                if(nums[mid] == target){
                    ans = mid;
                    right = mid -1;
                }
                else if(nums[mid] < target)
                    left = mid + 1;
                else 
                    right = mid - 1;
            }
            return ans;
        };
        auto rightPos = [](vector<int>& nums, int target){
            int left = 0, right = nums.size()-1;
            int ans = -1;
            while(left <= right){
                int mid = left + (right-left)/2;
                if(nums[mid] == target){
                    ans = mid;
                    left = mid+1;
                }
                else if(nums[mid] < target) 
                    left = mid + 1;
                else 
                    right = mid - 1;
            }
            return ans;
        };
        int first = leftPos(nums, target);
        int second = rightPos(nums, target);
        result.push_back(first);
        result.push_back(second);
        return result;
    }
};