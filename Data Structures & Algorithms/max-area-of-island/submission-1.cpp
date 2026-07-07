class DisjointSet{
private:
    vector<int> parent, size;
public:
    DisjointSet(int n){
        parent.resize(n);
        size.resize(n , 1);
        for(int i=0;i<n;i++)
            parent[i] = i;
    }
    int find(int x){
        if(parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }
    bool UnionByRank(int x, int y){
        int px = find(x);
        int py = find(y);
        if(px == py) return false;
        if(size[px] > size[py])
            swap(px, py);
        parent[py] = px;
        size[px] += size[py];
        return true;
    }
    int getSize(int x){
        return size[find(x)];
    }
};
class Solution {
    int direction[4][2] = {{-1,0}, {0, 1}, {1, 0},  {0, -1}};
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        DisjointSet obj(n*m);

        auto isValid = [&](int a, int b){
            return (a>=0 && a<n && b>=0 && b<m);
        };

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 0) continue;
                int index = i * m + j;
    
                for(int k=0;k<4;k++){
                    int x = i + direction[k][0];
                    int y = j + direction[k][1];
                    if(isValid(x, y) && grid[x][y] == 1){
                        obj.UnionByRank(index, x*m + y);
                    }   
                }
            }
        }

        int maxArea = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1) {
                    maxArea = max(maxArea, obj.getSize(i * m + j));
                }
            }
        }
        return maxArea;
    }
};
