class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        vector<int> indegree(n, 0) ;
        vector<int> adj[n] ;
        for(int i=0;i<pre.size();i++){
            adj[pre[i][1]].push_back(pre[i][0]) ;
            indegree[pre[i][0]] ++ ;
        }
        queue<int> q ;
        for(int i=0;i<n;i++){
            if(indegree[i] == 0){
                q.push(i) ;
            }
        }
        vector<int> ans;
        if(q.size()==0)return ans;

        while(!q.empty()){
            int len = q.size() ;
            for(int i=0;i<len;i++){
                int src = q.front() ;
                q.pop() ;
                ans.push_back(src) ;
                for(auto x: adj[src]){
                    indegree[x]--;
                    if(indegree[x] == 0)
                        q.push(x) ;
                }
            }
        }
        for(auto x:indegree)
            if(x>=1)return {};
        return ans;
    }
};
