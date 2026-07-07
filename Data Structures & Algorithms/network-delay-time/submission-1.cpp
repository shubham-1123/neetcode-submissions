class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>> adj[105] ;
        for(auto x: times){
            adj[x[0]].push_back({x[1], x[2]}) ;
        }
        vector<int> dis(n+1, INT_MAX) ;
        helper(adj, dis, k);
        int delayTime = INT_MIN;
        for(int i=1;i<=n;i++){
            if(dis[i] == INT_MAX) return -1;
            delayTime = max(delayTime, dis[i]);
        }
        return delayTime;
    }
    void helper(vector<pair<int,int>> adj[], vector<int>& dis, int src){
        queue<pair<int,int>> q; 
        dis[src] = 0 ;
        q.push({0, src}) ;

        while(!q.empty()){
            auto x = q.front() ;
            src = x.second;
            int d1 = x.first;
            q.pop() ;

            for(auto pt: adj[src]){
                int v = pt.first;
                int d = pt.second;

                if(d + d1 < dis[v]){
                    dis[v] = d + d1;
                    q.push({d+d1, v}) ;
                }
            }

        }
        return ;
    }
};
