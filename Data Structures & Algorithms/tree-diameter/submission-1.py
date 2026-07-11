class Solution:
    def treeDiameter(self, edges: List[List[int]]) -> int:
        n = len(edges) + 1
        adj = [[] for _ in range(n)]

        for u, v in edges:
            adj[u].append(v)
            adj[v].append(u)
    
        def dfs(u:int, parent:int, dist:int):
            farthest_node = u
            max_dist = dist
            for v in adj[u]:
                if v != parent:
                    node, d = dfs(v, u, dist+1)
                    if d > max_dist:
                        max_dist = d
                        farthest_node = node
            return farthest_node, max_dist

        a, _ = dfs(0, -1, 0)
        _, diameter = dfs(a, -1, 0)
        return diameter  
