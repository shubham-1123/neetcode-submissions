class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> result ;
        if(intervals.size() == 1)
            return intervals;
        sort(intervals.begin(), intervals.end());
        vector<int> temp = intervals[0];

        for(auto x: intervals){
            if(x[0]<= temp[1]){
                temp[1] = max(temp[1], x[1]) ;
                temp[0] = min(temp[0], x[0]) ;
            }else{
                result.push_back(temp) ;
                temp = x;
            }
        }
        result.push_back(temp) ;
        return result;
    }
};
