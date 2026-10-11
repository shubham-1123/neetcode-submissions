class Solution {
public:
    vector<int> adj[1001];
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses, 0);
        for(auto x : prerequisites){
            adj[x[1]].push_back(x[0]);
            indegree[x[0]] ++;
        }
        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(indegree[i] == 0)
                q.push(i);
        }
        if(q.empty())return false;
        while(!q.empty()){
            int src = q.front();
            q.pop();
            for(auto x: adj[src]){
                if(indegree[x]!= 0){
                    indegree[x] --;
                    if(indegree[x] == 0)
                        q.push(x);
                }
            }
        }
        for(int i=0;i<numCourses;i++)
            if(indegree[i] != 0)return false;
        return true;
    }
};
