class DSU{
public:
    vector<int> parent;
    vector<int> rank;
    DSU(int n){
        parent.resize(n);
        rank.resize(n, 1) ;
        for(int i=0;i<n;i++)
            parent[i] = i;
    }
    int find(int x){
        if(parent[x] == x)
            return x;
        return parent[x] = find(parent[x]) ;
    }
    bool unionByRank(int a, int b){
        int px = find(a) ;
        int py = find(b) ;
        if(px == py) return false;
        if(rank[px] > rank[py])
            swap(px, py);
        parent[py] = px ;
        rank[px] += rank[py];
        return true;
    }
};

class Solution {
public:
    bool checkCycle(vector<int> adj[], vector<int>& visited, int src, int parent){
        visited[src] = 1 ;
        for(auto x: adj[src]){
            if(!visited[x]){
                if(checkCycle(adj, visited, x, src))return true;
            }
            else if(x != parent){
                return true;
            }     
        }
        return false;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<int> adj[101] ;
        int component = n;
        DSU ob(n);
        for(auto x: edges){
            adj[x[0]].push_back(x[1]) ;
            adj[x[1]].push_back(x[0]) ;
            if(ob.unionByRank(x[0], x[1])){
                component -- ;
            }
        }

        if(component > 1) return false;
        vector<int> visited(n, 0);
        
        for(int i=0;i<n;i++){
            if(!visited[i]){
                if(checkCycle(adj, visited, i, -1)) return false;
            }
        }

        return true;
    }
};







