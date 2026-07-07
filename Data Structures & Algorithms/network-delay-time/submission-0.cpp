class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>> adj[101] ;
        for(auto x: times){
            vector<int> v = x ;
            adj[v[0]].push_back({v[1], v[2]});
        }
        vector<int> dis(n+1, INT_MAX);
        solve(adj, dis, k);
        int ans = -1;
        for(int i=1;i<dis.size();i++){
            if(ans<dis[i])
                ans = dis[i];
        }
        return (ans==INT_MAX)?-1:ans;
    }
    void solve(vector<pair<int,int>> adj[], vector<int>& dis, int src){
        queue<pair<int,int>>q;
        q.push({src,0});
        dis[src] = 0;

        while(!q.empty()){
            pair<int,int> x = q.front();
            q.pop();
            int u = x.first;
            int d = x.second;

            for(auto it: adj[u]){
                int v = it.first;
                int d1 = it.second ;
                if(d+d1 < dis[v]){
                    dis[v] = d+d1;
                    q.push({v, d+d1});
                }
            }
        }
    }
};
