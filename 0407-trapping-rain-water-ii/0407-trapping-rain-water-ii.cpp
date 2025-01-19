class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int m = heightMap.size();
        int n = heightMap[0].size();
        if (m <= 1 || n <= 1) return 0;
        
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        
        vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 || j == 0 || i == m-1 || j == n-1) {
                    pq.push({heightMap[i][j], {i, j}});
                    visited[i][j] = true;
                }
            }
        }
        
        int waterTrapped = 0;
        
        while (!pq.empty()) {
            auto [height, cell] = pq.top();
            pq.pop();
            int x = cell.first, y = cell.second;
            
            for (auto& dir : directions) {
                int nx = x + dir.first, ny = y + dir.second;
                
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && !visited[nx][ny]) {
                    visited[nx][ny] = true;
                    
                    if (heightMap[nx][ny] < height) {
                        waterTrapped += height - heightMap[nx][ny];
                    }
                    
                    pq.push({max(height, heightMap[nx][ny]), {nx, ny}});
                }
            }
        }
        
        return waterTrapped;
    }
};
