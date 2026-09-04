class Solution {
public:
    int connectSticks(vector<int>& sticks) {
        if(sticks.size() == 1)
            return 0;
        priority_queue<int, vector<int>, greater<int>> pq;
        for(auto x: sticks)
            pq.push(x);
        int minCost = 0;

        while(pq.size() >= 2){
            int a = pq.top();
            pq.pop();
            int b = pq.top();
            pq.pop();
            a = a + b;
            minCost += a ;
            std::cout << a << " " << minCost << '\n'; 
            pq.push(a);
        }
        // if(!pq.empty())
        //     minCost += pq.top();

        return minCost;
    }
};
