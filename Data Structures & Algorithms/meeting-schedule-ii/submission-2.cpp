/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        int n = intervals.size();
        if(n <= 1)return n;

        sort(intervals.begin(), intervals.end(), [](Interval& obj1, Interval& obj2){
            return obj1.start  <= obj2.start;
        });

        priority_queue<int, vector<int>, greater<int>> pq;
        pq.push(intervals[0].end);

        for(int i=1;i<n;i++){
            int start = intervals[i].start;
            int end = intervals[i].end;

            if(start >= pq.top())
                pq.pop();
            
            pq.push(end);

        }
        return pq.size();
    }
};
