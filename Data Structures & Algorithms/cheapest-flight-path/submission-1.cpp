class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>> adj[105];
        for(auto x: flights){
            adj[x[0]].push_back({x[1], x[2]});
        }
        vector<int> dis(n, INT_MAX) ;

        queue<pair<int,pair<int,int>>> q;
        q.push({0, {src,0}});
        dis[src] = 0;

        while(!q.empty()){
            auto x = q.front() ;
            q.pop();

            int d = x.first;
            src = x.second.first;
            int count = x.second.second;

            for(auto pt : adj[src]){
                int v = pt.first;
                int d1 = pt.second;

                if(d1+d < dis[v] && count <= k){
                    dis[v] = d1+d;
                    q.push({dis[v], {v, count + 1}}) ;
                }

            }

        }

        return (dis[dst] == INT_MAX)?-1:dis[dst];

    }
};
