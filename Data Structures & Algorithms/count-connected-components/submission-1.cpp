class Solution {
public:
    vector<int> parent;
    vector<int> rank;
    int find(int x){
        // int cur = x ;
        // while(cur !=  parent[cur]){
        //     parent[cur] = parent[parent[cur]];
        //     cur = parent[cur];
        // }
        // return cur;
        if(parent[x] == x)return x ;
        return parent[x] = find(parent[x]) ;
    }
    bool find(int a, int b){
        int x_ = find(a) ;
        int y_ = find(b) ;
        if(x_ == y_)return false;
        if(rank[x_]>rank[y_])
            swap(x_, y_);
        parent[y_] = x_;
        rank[x_]+=rank[y_];
        return true;
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        parent.resize(n) ;
        rank.resize(n,1) ;
        for(int i=0;i<n;i++)
            parent[i] = i ;
        int ans = n ;
        for(int i=0;i<edges.size();i++){
            if(find(edges[i][0], edges[i][1]))
                ans-- ;
        }
        // unordered_set<int> st ;
        // for(int i=0;i<n;i++){
        //     st.insert(parent[i]) ;
        // }
        return ans;
    }
};
