class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int maxLength = 1;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                maxLength = max(maxLength, dfs(matrix, i, j, -1));
            }
        }
        return maxLength;
    }
    int dfs(vector<vector<int>>& grid, int i, int j, int curr){
        if(i<0||i>=grid.size()||j<0||j>=grid[0].size()||grid[i][j]==-1||grid[i][j]<=curr)return 0;
        int maxAns = -1;
        int val = grid[i][j];
        grid[i][j] = 0;
        maxAns = max(maxAns, dfs(grid, i+1, j, val));
        maxAns = max(maxAns, dfs(grid, i-1, j, val));
        maxAns = max(maxAns, dfs(grid, i, j+1, val));
        maxAns = max(maxAns, dfs(grid, i, j-1, val));
        grid[i][j] = val;
        return 1 + maxAns;
    }
};
