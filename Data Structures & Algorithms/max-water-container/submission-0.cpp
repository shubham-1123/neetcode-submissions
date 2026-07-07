class Solution {
public:
    int maxArea(vector<int>& heights) {
        
        int max_water = 0 ; 

        int left =0, right = heights.size()-1 ;

        while(left < right){
            int diff = (right-left);
            int ans = min(heights[left], heights[right]) * diff ;
            max_water = max(max_water, ans) ;

            if(heights[left] <= heights[right])
                left ++;
            else
                right--;
        }
        return max_water;

    }
};
