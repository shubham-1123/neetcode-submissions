class DSU{
public:
    vector<int> parent;
    vector<int> rank;
    DSU(int n){
        parent.resize(n);
        rank.resize(n, 1) ;
        for(int i=0;i<n;i++)
            parent[i] = i;
    }
    int find(int x){
        if(parent[x] == x)return x;
        return parent[x] = find(parent[x]) ;
    }
    bool unionByRank(int a, int b){
        int px = find(a) ;
        int py = find(b) ;

        if(px == py) return false;

        if(rank[px] == rank[py])
            swap(px, py) ;
        parent[py] = px;
        rank[px] += rank[py] ;
        return true;
    }
};
class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<int> adj[105];
        for(auto x: edges){
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);            
        }
        DSU ob(n);
        int components = n;
        for(int i=0;i<n;i++){
            for(auto x: adj[i]){
                int u = i ;
                int v = x ;
                if(ob.unionByRank(u,v))
                    components --;
            }
        }
        return components;
    }
};















