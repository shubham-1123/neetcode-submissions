#include <cstring>
typedef pair<int,pair<int,int>> pr;
class Solution {
    int direction[4][2] = {{-1,0}, {0,1},{1,0},{0,-1}};
    int visited[101][101];
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        memset(visited, 0, sizeof(visited));
        priority_queue<pr, vector<pr>, greater<pr>> pq;
        pq.push({0, {0,0}});
        int minEffort = INT_MAX;

        while(!pq.empty()){
            pr p1 = pq.top();
            pq.pop();
            int d = p1.first;
            int x = p1.second.first;
            int y = p1.second.second;

            if(visited[x][y]==1)continue;
            visited[x][y] = 1;

            if(x == m-1 && y == n-1){
                minEffort = min(minEffort, d);
            }

            for(int i=0;i<4;i++){
                int x_ = x + direction[i][0];
                int y_ = y + direction[i][1];

                if(x_<0||x_>=m||y_<0||y_>=n||visited[x_][y_])continue;

                int diff = max(d, abs(heights[x][y]-heights[x_][y_]));
                pq.push({diff, {x_, y_}});
            }
        }
        return minEffort;
    }
};