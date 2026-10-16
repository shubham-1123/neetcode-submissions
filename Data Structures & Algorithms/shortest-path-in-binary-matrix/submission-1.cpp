typedef pair<int,pair<int,int>> pr;
class Solution {
public:
    int direction[8][2] = {{-1,0},{1,0},{0,1},{0,-1},{-1,1},{1,-1},{-1,-1},{1,1}};
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0] == 1) return -1;
        priority_queue<pr, vector<pr>, greater<pr>> pq;
        pq.push({1, {0,0}});
        grid[0][0] = 1;

        while(!pq.empty()){
            pr p = pq.top(); 
            pq.pop();

            int d = p.first;
            int i = p.second.first;
            int j = p.second.second;

            if((i == grid.size()-1) && (j == grid[0].size()-1)){
                return d;
            }
            
            for(int k=0;k<8;k++){
                int x = i + direction[k][0];
                int y = j + direction[k][1];
                if(x<0||x>=grid.size()||y<0||y>=grid[0].size()||grid[x][y]==1) continue;
                grid[x][y] = 1;
                pq.push({d+1, {x,y}});
            }
        }
        return -1;
    }
};