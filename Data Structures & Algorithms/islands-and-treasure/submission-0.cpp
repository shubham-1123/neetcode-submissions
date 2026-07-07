typedef pair<pair<int,int>,int> pr ;
class Solution {
public:
    int arrx[4] = {-1,0,1,0} ;
    int arry[4] = {0,1,0,-1} ;
    void islandsAndTreasure(vector<vector<int>>& grid) {
    
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j] == 0){
                    bfs(grid, i, j, 0) ;
                }
            }
        }
        return ;
    }
    void bfs(vector<vector<int>>& grid, int i, int j, int d){
        vector<vector<int>> visited(grid.size(), vector<int>(grid[0].size(), 0)) ;
        queue<pr> q;
        q.push({{i,j},0});

        while(!q.empty()){
            pr p = q.front() ;
            q.pop() ;
            int x = p.first.first;
            int y = p.first.second;
            int d = p.second;
            if(visited[x][y] == 1)continue;
            visited[x][y] = 1;

            for(int i=0;i<4;i++){
                int x_ = x + arrx[i] ;
                int y_ = y + arry[i] ;
                if(x_<0||x_>=grid.size()||y_<0||y_>=grid[0].size()||grid[x_][y_] == -1 || grid[x_][y_] == 0 || visited[x_][y_]==1)continue;
                grid[x_][y_] = min(grid[x_][y_], d+1) ;
                q.push({{x_,y_}, grid[x_][y_]}) ;
            }
        }
        return ;
        
    }
};






