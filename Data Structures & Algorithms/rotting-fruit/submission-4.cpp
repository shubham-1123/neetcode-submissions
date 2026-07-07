class Solution {
    int direction[4][2] ={{-1,0},{1,0},{0,1},{0,-1}};
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int fresh = 0;
        queue<pair<int,int>> q;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j] == 2){
                    q.push({i, j});
                }
                else if(grid[i][j] == 1)
                    fresh ++;
            }
        }
        if(fresh == 0)return 0;
        if(q.size() == 0)return -1;

        std::cout <<q.size() << '\n';
        auto isValid = [&](int a, int b){
            return (a>=0&&a<grid.size()&&b>=0&&b<grid[0].size());
        };

        int mintime = -1;
        while(!q.empty()){
            int n = q.size();
            mintime ++ ;
            for(int i=0;i<n;i++){
                auto src = q.front();
                q.pop();
                for(int k=0;k<4;k++){
                    int x = src.first + direction[k][0];
                    int y = src.second + direction[k][1];
                    if(isValid(x, y) && grid[x][y] == 1){
                        grid[x][y] = 2;
                        q.push({x, y});
                        fresh --;
                    }
                }
            }
        }
        if(fresh != 0) return -1;
        return mintime;
    }
};
