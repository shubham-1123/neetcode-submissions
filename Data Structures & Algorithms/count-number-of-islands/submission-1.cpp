class DisjointSet{
private:
    vector<int> parent, rank;
public:
    DisjointSet(int n){
        parent.resize(n);
        rank.resize(n, 1);
        for(int i=0;i<n;i++){
            parent[i] = i;
        }
    }
    int find(int x){
        if(parent[x] == x)return x;
        return parent[x] = find(parent[x]);
    }
    bool UnionByRank(int x, int y){
        int px = find(x);
        int py = find(y);

        if(px == py) return false;

        if(rank[px] > rank[py])
            swap(px, py);
        parent[py] = px;
        rank[px] += rank[py];
        return true;
    }
};

class Solution {
public:
    int direction[4][2] =  {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    int numIslands(vector<vector<char>>& grid) {
        int island = 0;
        int m = grid.size();
        int n = grid[0].size();

        auto isValid = [&](int a, int b){
            return (a>=0 && a<grid.size() && b>=0 && b<grid[0].size());
        };
        DisjointSet ob(m*n);

        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j] == '1')
                    island++;
            }
        }

        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){

                if(grid[i][j] != '1')continue;

                int index = i * n + j; 
                for(int k =0; k<4; k ++){
                    int x = direction[k][0] + i;
                    int y = direction[k][1] + j;
                    if(isValid(x, y) && grid[x][y] == '1'){
                        int newIndex = x*n + y;
                        if(ob.UnionByRank(index, newIndex))
                            island--;
                    }
                }
            }
        }
        return island;
    }
};
