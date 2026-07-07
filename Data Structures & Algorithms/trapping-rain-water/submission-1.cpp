class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size() ;
        if(n==1) return 0;

        int leftmax = height[0], rightmax = height[n-1] ;
        int l = 0, r = n-1;
        int ans = 0;
        while(l < r){
            if(leftmax < rightmax){
                l++;
                leftmax = max(leftmax, height[l]);
                ans += (leftmax-height[l]);
            }else{
                r -- ;
                rightmax = max(rightmax, height[r]) ;
                ans += (rightmax-height[r]);
            }
        }
        return ans;
    }
};
