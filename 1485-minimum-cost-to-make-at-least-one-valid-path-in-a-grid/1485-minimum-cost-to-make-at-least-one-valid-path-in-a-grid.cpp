class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        queue<pair<int, int>> q;
        vector<vector<int>> cost(m, vector<int>(n, -1));
        
        q.push({0, 0});
        cost[0][0] = 0;

        while (!q.empty()) {
            auto [i, j] = q.front();
            q.pop();
            
            int dir = grid[i][j] - 1;
            int x = i + directions[dir].first;
            int y = j + directions[dir].second;

            if (x >= 0 && x < m && y >= 0 && y < n && cost[x][y] == -1) {
                cost[x][y] = cost[i][j];
                q.push({x, y});
            }

            for (int k = 0; k < 4; k++) {
                int nx = i + directions[k].first;
                int ny = j + directions[k].second;
                
                if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
                    int newCost = (k != dir) ? 1 : 0;
                    if (cost[nx][ny] == -1 || cost[nx][ny] > cost[i][j] + newCost) {
                        cost[nx][ny] = cost[i][j] + newCost;
                        q.push({nx, ny});
                    }
                }
            }
        }

        return cost[m-1][n-1];
    }
};