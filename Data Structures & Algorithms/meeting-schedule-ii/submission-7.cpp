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
        if(n == 0)return 0;
        if(n == 1)return 1;

        sort(intervals.begin(), intervals.end(), [](Interval& obj1, Interval& obj2){
            return (obj1.start < obj2.start);
        });
        int min_rooms = INT_MIN;
        priority_queue<int, vector<int>, greater<int>> pq;
        for(auto& ptr: intervals){
            int s = pq.size();
            min_rooms = max(min_rooms, s);
            while(!pq.empty() && ptr.start >= pq.top())
                pq.pop();
            pq.push(ptr.end);
            s = pq.size();
            min_rooms = max(min_rooms, s);
        }
        return min_rooms;
    }
};
