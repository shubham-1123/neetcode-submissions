class DSU{
public:
    vector<int> parent;
    vector<int> rank;
    DSU(int n){
        parent.resize(n);
        rank.resize(n,1) ;
        for(int i=0;i<n;i++)
            parent[i] = i ;
    }
    int find(int src){
        if(parent[src]==src)
            return src;
        return parent[src] = find(parent[src]) ;
    }
    bool unionByRank(int a, int b){
        int px = find(a);
        int py = find(b);
        if(px == py)return false;
        if(rank[px] > rank[py])
            swap(px, py);
        parent[py] = px ;
        rank[px]+=rank[py] ;
        return true;
    }
};

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<vector<int>> adj;
        for(int i=0;i<points.size();i++){
            for(int j=i+1;j<points.size();j++){
                int diff = abs(points[i][0]-points[j][0]) + abs(points[i][1]-points[j][1]) ;
                adj.push_back({diff, i, j}) ;
            }
        }
        sort(adj.begin(), adj.end()) ;
        int n = points.size();
        DSU ob(n) ;

        int ans = 0;

        for(auto x: adj){
            int w = x[0];
            int u = x[1];
            int v = x[2] ;
            if(ob.unionByRank(u,v))
                ans+=w;
        }
        return ans;
    }
};
