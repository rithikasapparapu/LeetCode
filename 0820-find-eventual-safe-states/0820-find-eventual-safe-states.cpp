class Solution {
public:
    bool dfs(int node, vector<vector<int>>& graph, vector<int>& vis, vector<int>& pathVis, vector<int>& safe) {
        if (pathVis[node]) return true;
        if (vis[node]) return false;
        
        vis[node] = pathVis[node] = 1;
        
        for (int neighbor : graph[node]) {
            if (dfs(neighbor, graph, vis, pathVis, safe)) return true;
        }
        
        pathVis[node] = 0;
        safe[node] = 1;
        return false;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> safeNodes;
        vector<int> vis(n, 0), pathVis(n, 0), safe(n, 0);
        
        for (int i = 0; i < n; ++i) {
            if (!vis[i]) dfs(i, graph, vis, pathVis, safe);
        }
        
        for (int i = 0; i < n; ++i) {
            if (safe[i]) safeNodes.push_back(i);
        }
        
        return safeNodes;
    }
};
