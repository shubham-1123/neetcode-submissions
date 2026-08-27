class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {

        int index = 0, len = flowerbed.size();
        if(len == 1 && flowerbed[0] == 0){
            return (n<=1)?true:false;
        }
        while(index < len && n!=0){
            if(flowerbed[index] == 0){
                if(index+1 < len && (index == 0) && flowerbed[index+1] == 0){
                    flowerbed[index] = 1 ;
                    n --;
                }else if(index>0 && index+1 < len && flowerbed[index-1] == 0 && flowerbed[index+1] == 0){
                    flowerbed[index] = 1;
                    n --;
                }else if(index > 0 && index == len-1 && flowerbed[index-1] == 0){
                    flowerbed[index] = 1;
                    n --;
                }
            }
            index ++;
        }
        return(n == 0)?true:false;
    }
};