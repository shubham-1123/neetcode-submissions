class DSU{
public:
    vector<int> parent;
    vector<int> rank;
    DSU(int n){
        parent.resize(n);
        rank.resize(n, 1);
        for(int i=0;i<n;i++){
            parent[i] = i;
        }
    }
    int find(int x){
        if(parent[x] == x)return x;
        return parent[x] = find(parent[x]) ;
    }
    bool unionByRank(int x, int y){
        int px = find(x) ;
        int py = find(y) ;

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
    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<tuple<int,int,int>> adj;
        for(int i=0;i<points.size();i++){
            for(int j=0;j<points.size();j++){
                if(i != j){
                    int diff = abs(points[i][0]-points[j][0]) + abs(points[i][1] - points[j][1]) ;
                    adj.push_back({diff, i, j}) ;
                }
            }
        }
        int n = points.size() ;
        sort(adj.begin(), adj.end()) ;

        DSU ob(n);
        int minCost = 0 ;
        for(auto x: adj){
            tuple<int,int,int> t = x ;
            int d = get<0>(t);
            int u = get<1>(t);
            int v = get<2>(t);

            if(ob.unionByRank(u, v)){
                minCost += d;
            }
        }
        return minCost ;
    }
};
