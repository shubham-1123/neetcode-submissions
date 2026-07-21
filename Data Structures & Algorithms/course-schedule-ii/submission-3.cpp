class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[1001];
        vector<int> indegree(numCourses, 0);
        for(auto&x : prerequisites){
            adj[x[1]].push_back(x[0]);
            indegree[x[0]] ++; 
        }
        queue<int> q ;
        for(int i=0;i<numCourses;i++){
            if(indegree[i] == 0)
                q.push(i);
        }
        if(q.size() == 0) return {};
        vector<int> sequence;
        while(!q.empty()){
            int src = q.front();
            q.pop();
            sequence.push_back(src);
            for(auto x: adj[src]){
                indegree[x] -- ;
                if(indegree[x] == 0)
                    q.push(x);
            }
        }
        if(sequence.size()!=numCourses)
            return {};
        return sequence;

    }
};
