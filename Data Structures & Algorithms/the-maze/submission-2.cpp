#include <cstring>

class Solution {
public:
    int visited[101][101];
    int m, n;
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        memset(visited, 0, sizeof(visited));
        m = maze.size(), n = maze[0].size();
        return dfs(maze, start[0], start[1], destination);
    }
    bool dfs(vector<vector<int>>& maze, int i, int j, vector<int>& dest){
        if(visited[i][j])return false;
        if(i == dest[0] && j == dest[1])return true;
        
        int direction[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}}; //4 direction
        
        visited[i][j] = 1;
        for(auto pt : direction){
            int x = i, y = j;

            while(pt[0]+x >= 0 && pt[0]+x < m && pt[1]+y >= 0 && pt[1]+y<n && maze[pt[0]+x][pt[1]+y] ==0){
                x += pt[0];
                y += pt[1];
            }

            if(dfs(maze, x, y, dest))
                return true;
        }

        return false;
    }
};
