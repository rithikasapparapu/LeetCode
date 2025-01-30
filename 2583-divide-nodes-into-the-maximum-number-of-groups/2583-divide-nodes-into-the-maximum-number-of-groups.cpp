class Solution {
    bool isBipartiteComponent(vector<vector<int>>& graph, vector<int>& colors, int node) {
        queue<int> q;
        q.push(node);
        colors[node] = 1;

        while (!q.empty()) {
            int current = q.front();
            q.pop();

            for (int neighbor : graph[current]) {
                if (colors[neighbor] == 0) {
                    colors[neighbor] = -colors[current];
                    q.push(neighbor);
                } else if (colors[neighbor] == colors[current]) {
                    return false;
                }
            }
        }
        return true;
    }

    bool isGraphBipartite(vector<vector<int>>& graph, int n) {
        vector<int> colors(n + 1, 0);
        for (int i = 1; i <= n; ++i) {
            if (colors[i] == 0 && !isBipartiteComponent(graph, colors, i)) {
                return false;
            }
        }
        return true;
    }

    int calculateLevels(vector<vector<int>>& graph, int n, int start) {
        vector<bool> visited(n + 1, false);
        queue<int> q;
        q.push(start);
        visited[start] = true;

        int levelCount = 0;
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                int current = q.front();
                q.pop();

                for (int neighbor : graph[current]) {
                    if (!visited[neighbor]) {
                        visited[neighbor] = true;
                        q.push(neighbor);
                    }
                }
            }
            levelCount++;
        }
        return levelCount;
    }

    int getMaxLevelsFromBFS(vector<int>& levelDistances, vector<vector<int>>& graph, vector<bool>& visited, int start) {
        queue<int> q;
        q.push(start);
        visited[start] = true;

        int maxLevels = -1;
        while (!q.empty()) {
            int current = q.front();
            q.pop();

            maxLevels = max(maxLevels, levelDistances[current]);
            for (int neighbor : graph[current]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
        return maxLevels;
    }

public:
    int magnificentSets(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n + 1);
        for (auto edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        if (!isGraphBipartite(graph, n)) {
            return -1;
        }

        vector<int> levelDistances(n + 1);
        for (int i = 1; i <= n; ++i) {
            levelDistances[i] = calculateLevels(graph, n, i);
        }

        vector<bool> visited(n + 1, false);
        int totalLevels = 0;
        for (int i = 1; i <= n; ++i) {
            if (!visited[i]) {
                totalLevels += getMaxLevelsFromBFS(levelDistances, graph, visited, i);
            }
        }
        return totalLevels;
    }
};
