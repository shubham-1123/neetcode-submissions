class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int> aux(ratings.size(), 1);
        for(int i=1;i<ratings.size();i++){
            if(ratings[i] > ratings[i-1] && aux[i] <= aux[i-1]){
                aux[i] = 1 + aux[i-1];
            }
        }
        // for(auto x: aux)
        //     cout << x << " ";
        // cout << endl;

        for(int i=ratings.size()-2;i>=0;i--){
            if(ratings[i] > ratings[i+1] && aux[i] <= aux[i+1]){
                aux[i] = 1 + aux[i+1];
            }
        }
        // for(auto x: aux)
        //     cout << x << " ";
        // cout << endl;

        int minCandy = 0;
        for(auto x: aux)
            minCandy +=x ;
        return minCandy;
    }
};