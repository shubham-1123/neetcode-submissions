class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size() == 1)
            return intervals;
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> result;
        vector<int> v = intervals[0];
        
        for(auto x: intervals){
            if(v[1] >= x[0]){
                v[0] = min(v[0], x[0]);
                v[1] = max(v[1], x[1]);
            }else{
                result.push_back(v);
                v = x;
            }
        }
        result.push_back(v);
        return result;
    }
};
