class Solution {
    vector<pair<int,int>> adj[1001];
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        for(auto &x : times){
            adj[x[0]].push_back({x[1], x[2]});
        }
        vector<int> distance(n+1, INT_MAX);
        queue<pair<int,int>> q;
        q.push({k, 0});
        distance[k] = 0;
        while(!q.empty()){
            auto pt = q.front();
            q.pop();
            
            for(auto x : adj[pt.first]){
                int v = x.first;
                int d = x.second;
                if(distance[v] > d + pt.second){
                    distance[v] = d + pt.second;
                    q.push({v, distance[v]});
                }
            }
        }
        int minTime = INT_MIN;
        for(int i=1;i<=n;i++){
            // std::cout << distance[i] << " ";
            minTime = max(minTime, distance[i]);
        }
        return (minTime!=INT_MAX)?minTime:-1;
    }
};
