class Solution {
public:
    int check(vector<vector<int>>& grid, int i, int j, bool& flag){
        int m = grid.size(), n = grid[0].size();
        int val = 0;
        for(int k=0;k<n;k++){
            if(k == j)continue;
            if(grid[i][k] == 1){
                grid[i][k] = 2;
                val ++;
                flag = true;
            }else if(grid[i][k] == 2){
                flag = true;
            }
        }
        for(int k=0;k<m;k++){
            if(k == i)continue;
            if(grid[k][j] == 1){
                grid[k][j] = 2;
                val ++;
                flag = true;
            }else if(grid[k][j] == 2){
                flag = true;
            }
        }

        return val;

    }
    int countServers(vector<vector<int>>& grid) {
        int numberOfServers = 0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                int ans = 0;
                if(grid[i][j] == 1){
                    dfs(grid, i, j, ans);
                }
                if(ans > 1)
                    numberOfServers += ans;
                else if(ans == 1){
                    bool flag = false;
                    int val = 0;
                    val = check(grid, i, j, flag);
                    if(flag)
                        val ++;
                    numberOfServers += val;
                }
            }
        }
        return numberOfServers;
    }
    void dfs(vector<vector<int>>& grid, int i, int j, int& ans){
        if(i<0||i>=grid.size()||j<0||j>=grid[0].size()||grid[i][j]!=1)return;

        grid[i][j] = 2;
        ans ++ ;
        dfs(grid, i+1, j, ans);
        dfs(grid, i-1, j, ans);
        dfs(grid, i, j-1, ans);
        dfs(grid, i, j+1, ans);
        return;
    }
};