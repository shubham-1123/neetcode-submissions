typedef pair<int, pair<int,int>> pr ;
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>> adj[101] ;
        for(auto it: flights){
            adj[it[0]].push_back({it[1], it[2]}) ;
        }
        vector<int> dis(n, INT_MAX) ;
        solve(adj, dis, src, dst, k) ;
        return (dis[dst] == INT_MAX)?-1:dis[dst];

    }
    void solve(vector<pair<int,int>> adj[], vector<int>& dis, int src, int dest, int k){
        queue<pr> pq;
        dis[src]=0;
        pq.push({0, {src, 0}}) ;
        
        while(!pq.empty()){
            pr p = pq.front();
            pq.pop() ;

            int d1 = p.first ;
            src = p.second.first ;
            int count = p.second.second;

            for(auto x:  adj[src]){
                pair<int,int> arr = x ;
                int v = arr.first ;
                int d2 = arr.second ;

                if(d1+d2 < dis[v] && count <= k){
                    dis[v] = d1+d2 ;
                    pq.push({d1+d2, {v, count+1}}) ;
                }
            }
        }

    }
};

