typedef pair<int, pair<int,int>> pr;
class Solution {
public:
    int direction[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
    int n, m;
    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        n = maze.size(), m = maze[0].size();
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        priority_queue<pr, vector<pr>, greater<pr>> pq;
        pq.push({0, {start[0], start[1]}});
        dist[start[0]][start[1]] = 0;

        while(!pq.empty()){
            pr p = pq.top();
            pq.pop();
            int d = p.first ;
            int x = p.second.first;
            int y = p.second.second;

            if(x == destination[0] && y == destination[1]){
                return dist[x][y];
            }

            for(auto t : direction){
                int x1 = x, y1 = y, steps = 0;
                while(x1+t[0]>=0 && x1+t[0]<n && y1+t[1]>=0 && y1+t[1]<m && maze[x1+t[0]][y1+t[1]] != 1){
                    x1 = x1 + t[0];
                    y1 = y1 + t[1];
                    steps ++;
                }
                if(dist[x][y] + steps < dist[x1][y1]){
                    dist[x1][y1] = dist[x][y]+steps;
                    pq.push({dist[x1][y1], {x1, y1}}) ;
                }
            }
        }
        return -1;
    }
};












