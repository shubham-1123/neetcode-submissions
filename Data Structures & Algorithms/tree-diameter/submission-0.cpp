class Solution {
public:
    pair<int,int> dfs(int u, int parent, vector<int> adj[], int dist){
        pair<int,int> best  = {dist, u};
        for(int v : adj[u]){
            if(v != parent){
                auto res = dfs(v, u, adj, dist+1);
                if(res.first > best.first)
                    best = res;
            }
        }
        return best;
    }
    int treeDiameter(vector<vector<int>>& edges) {
        vector<int> adj[10001];
        for(auto& x: edges){
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        auto[dist1, u] = dfs(0, -1, adj, 0);
        auto[diameter, v] = dfs(u, -1, adj, 0);
        return diameter;
    }
};
