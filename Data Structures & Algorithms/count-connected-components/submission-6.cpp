class Solution {
public:
    void dfs(vector<int> adj[], int src, vector<int>& visited){
        visited[src] = 1;
        for(auto x: adj[src]){
            if(!visited[x]){
                dfs(adj, x, visited);
            }
        }
        return;
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<int> adj[2001];
        for(auto x: edges){
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }

        vector<int> visited(n, 0);
        int count = 0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                dfs(adj, i, visited);
                count ++ ;
            }
        }
        return count;
    }
};
