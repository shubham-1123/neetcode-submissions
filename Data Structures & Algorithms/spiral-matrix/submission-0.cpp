class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int top = 0, left =0, down = matrix.size()-1, right = matrix[0].size()-1;
        int direction = 0;
        vector<int> result; 
        result.resize(matrix.size() * matrix[0].size());
        int k = 0;
        while(top <= down && left <= right){
            if(direction == 0){
                for(int i=left;i<=right;i++)
                    result[k++] = matrix[top][i];
                top ++ ;
            }else if(direction == 1){
                for(int i=top;i<=down;i++)
                    result[k++] = matrix[i][right];
                right --;
            }else if(direction == 2){
                for(int i=right;i>=left;i--)
                    result[k++] = matrix[down][i];
                down--;
            }else if(direction == 3){
                for(int i=down;i>=top;i--)
                    result[k++] = matrix[i][left];
                left++;
            }
            direction = (direction + 1)%4;
        }
        return result;
    }
};
