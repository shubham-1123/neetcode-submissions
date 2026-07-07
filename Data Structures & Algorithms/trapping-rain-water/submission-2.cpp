class Solution {
public:
    int trap(vector<int>& height) {
        int left=0, right= height.size()-1;
        int leftmax = height[0], rightmax = height[right];
        int trapwater = 0;
        while(left < right){
            if(leftmax < rightmax){
                left ++ ;
                leftmax = std::max(leftmax, height[left]);
                trapwater += (leftmax-height[left]);
            }else{
                right -- ;
                rightmax = std::max(rightmax, height[right]);
                trapwater += (rightmax-height[right]) ;
            }
        }
        return trapwater;
    }
};
// Input: height = [0,2,0,3,1,0,1,3,2,1]
// Output: 9