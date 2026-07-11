class Solution {
public:
    int dfs(vector<int> adj[], vector<bool>& hasApple, int src, int parent){

        int totalTime = 0;

        for(auto child : adj[src]){

            if(child == parent) continue;

            int childTime = dfs(adj, hasApple, child, src);

            if(childTime > 0 || hasApple[child]){
                totalTime += childTime + 2;
            }
        }  
        return  totalTime;

    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<int> adj[100001];
        for(auto x: edges){
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        return dfs(adj, hasApple, 0, -1);
    }
};