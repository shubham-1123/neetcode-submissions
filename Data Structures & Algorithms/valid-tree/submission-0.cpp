class Solution {
public:
    vector<int> parent;
    vector<int> rank ;
    int find(int x){
        if(parent[x] == x)return x;
        return parent[x] = find(parent[x]) ; 
    }
    bool union1(int a, int b){
        int x_ = find(a);
        int y_ = find(b);
        if(x_ == y_)
            return false;
        if(rank[x_] > rank[y_])
            swap(x_, y_);
        parent[y_] = x_;
        rank[x_] += rank[y_] ;
        return true; 
    }
    bool checkCycle(vector<int> adj[], vector<int>& visited, int src, int parent){
        visited[src] = 1 ;
        for(auto x: adj[src]){
            if(!visited[x]){
                if(checkCycle(adj, visited, x, src))
                    return true;
            }
            else if(x != parent)
                return true;
        }
        return false;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        parent.resize(n) ;
        rank.resize(n, 1) ;
        for(int i=0;i<n;i++)
            parent[i] = i;
        int comp = n ;
        vector<int> adj[n] ;
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]) ;
            adj[edges[i][1]].push_back(edges[i][0]) ;
            vector<int> v = edges[i] ;
            if(union1(v[0], v[1])){
                comp -- ;
            }
        }
        // cout << comp << " " ;
        if(comp > 1) return false;
        
        vector<int> visited(n, 0) ;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                if(checkCycle(adj, visited, i, -1))
                    return false;
            }
        }
        return true;
    }
};
