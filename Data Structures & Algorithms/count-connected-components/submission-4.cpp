class DSU{
    vector<int> parent;
    vector<int> rank;
public:
    DSU(int n){
        parent.resize(n);
        for(int i=0;i<n;i++)
            parent[i] = i;
        rank.resize(n, 0);
    }
    int find(int x){
        if(parent[x] == x)
            return x;
        return parent[x] = find(parent[x]);
    }
    bool unionByRank(int x, int y){
        int px = find(x);
        int py = find(y);
        if(px == py) return false;
        if(rank[px] > rank[py]){
            swap(px, py);
        }
        parent[py] = px;
        rank[px] += rank[py] ;
        return true;    
    }

};
class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<int> adj[101];
        for(auto x: edges){
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }

        DSU ob(n);
        int components = n;
        for(int i=0;i<n;i++){
            for(auto x: adj[i]){
                int u = i;
                int v = x;
                if(ob.unionByRank(u, v)){
                    components -- ;
                }
            }
        }
        return components;

    }
};
