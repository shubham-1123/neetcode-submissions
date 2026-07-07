class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> order, indegree(numCourses,0);
        vector<int> adj[1001];

        for(auto &x : prerequisites){
            indegree[x[0]] ++;
            adj[x[1]].push_back(x[0]);
        }
        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(indegree[i] == 0)
                q.push(i);
        }
        if(q.size() == 0)return {};

        while(!q.empty()){
            int n = q.size();
            for(int i=0;i<n;i++){
                int src = q.front();
                q.pop();
                order.push_back(src);
                for(auto x : adj[src]){
                    indegree[x]--;
                    if(indegree[x] == 0)
                        q.push(x);
                }
            }
        }
        for(auto x:indegree)
            if(x>=1)return {};
        return order;
    }
};

