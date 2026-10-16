class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0, right = height.size()-1;
        int leftmax = 0, rightmax = 0;
        int maxWater = 0 ;
        while(left <= right){
            if(leftmax <= rightmax){
                leftmax = max(leftmax, height[left]);
                maxWater += (leftmax - height[left]);
                left ++;
            }else{
                rightmax = max(rightmax, height[right]);
                maxWater += (rightmax-height[right]);
                right--;
            }
        }
        return maxWater;
    }
};
