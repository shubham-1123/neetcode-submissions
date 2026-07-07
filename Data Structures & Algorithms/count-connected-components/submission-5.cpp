class Solution {
public:
    void dfs(int src, vector<int> adj[], unordered_set<int>& visited){
        visited.insert(src);
        for(auto x: adj[src]){
            if(!visited.count(x))
                dfs(x, adj, visited);
        }
        return;
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<int> adj[2001];
        unordered_set<int> visited;
        for(auto &x : edges){
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        int components = 0;

        // auto dfs = [&](int src){
        //     visited.insert(src);
        //     for(auto x: adj[src]){
        //         if(!visited.count(x))
        //             dfs(x);
        //     }
        //     return;
        // };


        for(int i=0;i<n;i++){
            if(!visited.count(i)){
                dfs(i, adj, visited);
                components ++ ;
            }
        }
        return components;
    }
};
