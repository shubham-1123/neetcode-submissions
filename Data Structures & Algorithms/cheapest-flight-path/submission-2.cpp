class Solution {
    vector<array<int, 2>> adj[101];
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        for(const auto &x : flights){
            adj[x[0]].push_back({x[1], x[2]});
        }
        vector<int> distance(n, INT_MAX);
        queue<array<int,3>> q;
        q.push({0, src, 0});
        distance[src] = 0;

        while(!q.empty()){
            auto x = q.front();
            q.pop();
            int count = x[2];

            for(auto ptr : adj[x[1]]){
                int v = ptr[0];
                int d = ptr[1];

                if(d + x[0] < distance[v] && count <= k){
                    distance[v] = d + x[0];
                    q.push({distance[v], v, count + 1});
                }
            }
        }

        return (distance[dst] != INT_MAX)?distance[dst]:-1;

    }
};
