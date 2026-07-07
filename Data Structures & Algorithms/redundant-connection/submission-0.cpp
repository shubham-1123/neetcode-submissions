class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        unordered_map<int, vector<int>>mp;
        for(int i=0;i<edges.size();i++){
            int u = edges[i][0] ;
            int v = edges[i][1] ;
            vector<bool> visited(edges.size(), false) ;
            if(mp.find(u)!= mp.end() && mp.find(v)!= mp.end() && bfs(visited,mp,u,v)){
                return edges[i] ;
            }
            mp[u].push_back(v);
            mp[v].push_back(u) ;
        }
        return {} ;
    }
    bool bfs(vector<bool>& visited, unordered_map<int,vector<int>>& mp, int u, int v){
        queue<int> q ;
        q.push(u) ;
    
        while(!q.empty()){
            u = q.front() ;
            q.pop() ;
            if(u == v)return true;
            if(visited[u]) continue;
            visited[u] = true;
            for(auto x: mp[u]){
                if(!visited[x]){
                    q.push(x) ;
                }
            }
        }
        return false;
    }
};
