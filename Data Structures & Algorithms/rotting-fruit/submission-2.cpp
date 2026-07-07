class Solution {
public:
    int arrx[4] = {-1,0,1,0} ;
    int arry[4] = {0,1,0,-1} ;
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q ;
        int numberOfOne =0 ;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j] == 2){
                    q.push({i, j}) ;
                }
                if(grid[i][j] == 1)
                    numberOfOne ++ ;
            }
        }
        if(q.size() == 0){
            return (numberOfOne == 0)?0:-1;
        }
        int t = 0;
        while(!q.empty()){
            int n = q.size() ;
            t ++ ;
            for(int i=0;i<n;i++){
                pair<int,int> pr = q.front();
                q.pop() ;
                int x = pr.first;
                int y = pr.second;
                for(int i=0;i<4;i++){
                    int x_ = x + arrx[i] ;
                    int y_ = y + arry[i] ;
                    if(x_<0||x_>=grid.size()||y_<0||y_>=grid[0].size()||grid[x_][y_]!=1)continue;
                    grid[x_][y_]=2 ;
                    q.push({x_,y_}) ;
                    numberOfOne-- ;
                }
            }
        }
        return (numberOfOne==0)?(t-1):-1;
    }
};
