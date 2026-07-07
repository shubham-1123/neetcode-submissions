class DSU{
    vector<int> parent;
    vector<int> rank;
public:
    DSU(int n){
        parent.resize(n, 0);
        rank.resize(n, 1);
        for(int i=0;i<n;i++){
            parent[i] = i;
        }
    }
    int find(int x){
        if(x == parent[x]) return x;
        return parent[x] = find(parent[x]);
    }
    bool UnionByRank(int x, int y){
        int px = find(x);
        int py = find(y);
        if(px == py)return false;
        if(rank[px] > rank[py]){
            swap(px, py);
        }
        parent[py] = px;
        rank[px] += rank[py];
        return true;
    }
};

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<std::array<int, 3>> input;

        auto dist = [&](vector<int>& point1, vector<int>& point2){
            return abs(point1[0]-point2[0]) + abs(point1[1]-point2[1]);
        };

        for(int i=0;i<points.size();i++){
            for(int j=0;j<points.size();j++){
                if(i != j){
                    int cost = dist(points[i], points[j]);
                    input.push_back({cost, i, j});
                } 
            }
        }
        sort(input.begin(), input.end());

        DSU ob(points.size());

        int minCost = 0 ;

        for(auto& ptr : input){
            if(ob.UnionByRank(ptr[1], ptr[2])){
                minCost += ptr[0];
            }
        }
        return minCost;
    }
};







