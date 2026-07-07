class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        if(intervals.size() == 1) return intervals;

        vector<vector<int>> result;
        vector<int> curr = intervals[0];

        for(auto x : intervals){
            if(curr[1] >= x[0]){
                curr[0] = min(curr[0], x[0]);
                curr[1] = max(curr[1], x[1]);
            }else{
                result.push_back(curr);
                curr = x;
            }
        }
        result.push_back(curr);
        return result;
    }
};
