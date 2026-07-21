class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int capacity = gas[0]-cost[0];
        int start = 0, end = 1, n=gas.size();

        if(gas.size() == 1){
            return (capacity >= 0)?0:-1;
        }

        while(capacity < 0 || (start != end)){
            while(capacity<=0 && start!=end){
                capacity -= (gas[start]-cost[start]);
                start = (start+1)%n;
                if(start == 0)return -1;
            }
            capacity += (gas[end] - cost[end]);
            end = (end+1)%n; 
        }
        return start;
    }
};
