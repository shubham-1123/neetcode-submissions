typedef pair<int,pair<int,int>> pr;
class Solution {
public:
    int arr_x[4] = {-1,0,1,0};
    int arr_y[4] = {0,1,0,-1};
    int minimumEffortPath(vector<vector<int>>& heights) {
        
        priority_queue<pr, vector<pr>, greater<pr>>pq;
        pq.push({0, {0, 0}});
        int row = heights.size();
        int col = heights[0].size() ;
        vector<vector<int>> visited(row, vector<int>(col, 0));
        int minEffort = INT_MAX;

        while(!pq.empty()){
            pr p = pq.top();
            pq.pop();

            int d = p.first;
            int x = p.second.first;
            int y = p.second.second;

            if(visited[x][y])continue;
            visited[x][y] = 1 ;

            if((x == row-1) && (y == col-1)){
                minEffort = min(minEffort, d);
            }

            for(int i=0;i<4;i++){
                int x1 = x + arr_x[i];
                int y1 = y + arr_y[i];
                if(x1<0 || x1 >= row || y1<0 || y1 >= col || visited[x1][y1])continue;
                int diff = abs(heights[x][y] - heights[x1][y1]);
                pq.push({max(d, diff), {x1, y1}});
            }
        }

        return minEffort;

    }
};