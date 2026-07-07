class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int left=0, right = people.size()-1;
        int boats = 0;
        while(left < right){
            if(people[left]+people[right] <= limit){
                left ++;
                right --;
                boats ++;
            }else if(people[left] >= limit){
                left ++ ;
                boats ++;
            }else if(people[right] >= limit){
                right --;
                boats++;
            }else if(people[left] + people[right] > limit){
                if(people[left] < people[right]){
                    right -- ;
                    boats ++ ;
                }else if(people[left]  == people[right]){
                    left ++;
                    right --;
                    boats += 2;
                }
            }
        }
        if(left  == right) boats++;
        return boats;
    }
};