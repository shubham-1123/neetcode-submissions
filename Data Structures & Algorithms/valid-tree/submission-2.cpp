class Solution {
    vector<int> adj[101];
public:
    void dfs(int src, unordered_set<int>& visited){
        visited.insert(src);
        for(auto x : adj[src]){
            if(!visited.count(x)){
                dfs(x, visited);
            }
        }
        return;
    }
    bool checkCycle(int src, int parent,  unordered_set<int>& visited){
        visited.insert(src);

        for(auto x: adj[src]){
            if(!visited.count(x)){
                if(checkCycle(x, src, visited))return true;
            }else if(x != parent){
                return true;
            }
        }
        return false;
    }

    bool validTree(int n, vector<vector<int>>& edges) {
        for(auto &x: edges){
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        int components = 0;
        unordered_set<int> visited;

        for(int i=0;i<n;i++){
            if(components > 1)return false;
            if(!visited.count(i)){
                dfs(i, visited);
                components ++;
            }
        }
        std::cout<<components << '\n';
        if(components > 1)return false;
        visited.clear();

        for(int i=0;i<n;i++){
            if(!visited.count(i)){
                if(checkCycle(i, -1, visited))return false;
            }
        }
        return true;
    }
};
