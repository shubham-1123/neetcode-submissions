#include <cstring>

class Solution {
    int row, col;
    int dp[101][101];
public:
    int helper(vector<vector<int>>& grid, int i, int j, int curr){
        if(i<0||i>=row||j<0||j>=col|| grid[i][j] == -1 || grid[i][j] <= curr) return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        int maxLen = 0;
        maxLen = max(maxLen, 1 + helper(grid, i+1, j, grid[i][j]));
        maxLen = max(maxLen, 1 + helper(grid, i-1, j, grid[i][j]));
        maxLen = max(maxLen, 1 + helper(grid, i, j+1, grid[i][j]));
        maxLen = max(maxLen, 1 + helper(grid, i, j-1, grid[i][j]));
        return dp[i][j] = maxLen; 
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        row = matrix.size(), col = matrix[0].size();
        int maxLength = 1;
        memset(dp, -1, sizeof(dp));
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                maxLength = max(maxLength, helper(matrix, i, j, -1));
            }
        }
        return maxLength;
    }
};
