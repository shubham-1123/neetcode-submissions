class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ans(2,0);
        int left = 0, right = numbers.size()-1;
        while(left < right){
            int sum = numbers[left] + numbers[right];
            if(sum > target)
                right --;
            else if(sum < target)
                left ++;
            else if(sum == target){
                ans[0] = left+1 ;
                ans[1] = right+1;
                break;
            }
        }
        return ans;
    }
};
