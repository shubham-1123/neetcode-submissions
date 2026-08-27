class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> spiral(n, vector<int>(n,0));
        int left = 0, top = 0, right = n-1, down = n-1;
        int direction = 0, start = 1;

        while(top <= down  && left <= right){
            if(direction==0){
                for(int i=left;i<=right;i++){
                    spiral[top][i] = start++;
                }
                top ++;
            }
            else if(direction == 1){
                for(int i=top;i<=down;i++){
                    spiral[i][right] = start ++;
                }
                right --;
            }
            else if(direction == 2){
                for(int i=right;i>=left;i--){
                    spiral[down][i] = start ++;
                }
                down--;
            }else if(direction == 3){
                for(int i=down;i>=top;i--){
                    spiral[i][left] = start ++;
                }
                left++;
            }
            direction = (direction+1)%4;
        }
        return spiral;
    }
};