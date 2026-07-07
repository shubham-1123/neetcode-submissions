class Solution {
public:
    int maxArea(vector<int>& heights) {
        int left = 0, right = heights.size()-1;
        int maxArea = 0;
        auto max = [](int a, int b){
            return (a>b)?a:b;
        };
        auto min = [](int a, int b){
            return (a<b)?a:b;
        };
        while(left < right){
            int val = min(heights[left], heights[right]) * (right-left) ;
            maxArea = max(maxArea, val);
            if(heights[left] <= heights[right])
                left ++;
            else 
                right --;
        }
        return maxArea;
    }
};
