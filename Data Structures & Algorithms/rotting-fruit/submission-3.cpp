class Solution {
public:
    int arrx[4] = {-1,0,1,0};
    int arry[4] = {0,1,0,-1};
    int orangesRotting(vector<vector<int>>& grid) {
        int count_one = 0;
        queue<pair<int,int>> q;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j] == 1){
                    count_one ++ ;
                    continue;
                }
                else if(grid[i][j] == 2){
                    q.push({i, j});
                }
            }
        }

        if(count_one == 0) return 0; 
        if(q.size() == 0) return -1;
        int tm = -1;
        while(!q.empty()){
            int n = q.size() ;
            tm ++ ;
            for(int i=0;i<n;i++){
                pair<int,int> p = q.front() ;
                q.pop() ;
                int x = p.first;
                int y = p.second;

                for(int i=0;i<4;i++){
                    int x1 = x + arrx[i] ;
                    int y1 = y + arry[i] ;

                    if(x1<0||x1>=grid.size()||y1<0||y1>=grid[0].size()||grid[x1][y1] != 1) continue;

                    grid[x1][y1] = 2;
                    count_one -- ;
                    q.push({x1, y1}) ;
                }
            }
        }

        return (count_one == 0) ? tm : -1;
    }
};
