#include <cstring>
typedef pair<int, pair<int,int>> pr;
class Solution {
    int direction[4][2] = {{-1,0}, {0, 1}, {1, 0}, {0, -1}};
    int visited[101][101];
public:
    int maximumMinimumPath(vector<vector<int>>& grid) {
        memset(visited, 0, sizeof(visited));
        priority_queue<pair<int, pair<int,int>>> pq; //max priority queue
        pq.push({grid[0][0], {0, 0}});

        int minMax = INT_MIN;

        while(!pq.empty()){
            pr p1 = pq.top();
            pq.pop();
            int d = p1.first;
            int x = p1.second.first;
            int y = p1.second.second;
            
            if(x == grid.size()-1 && y == grid[0].size()-1){
                minMax = max(minMax, d);
            }

            if(visited[x][y])continue;
            visited[x][y] = 1;

            for(int i=0;i<4;i++){
                int x_ = x + direction[i][0];
                int y_ = y + direction[i][1];
                if(x_<0||x_>=grid.size()||y_<0||y_>=grid[0].size()||visited[x_][y_])continue;
                pq.push({min(d, grid[x_][y_]), {x_, y_}});
            }
        }
        return minMax;
    }
};
