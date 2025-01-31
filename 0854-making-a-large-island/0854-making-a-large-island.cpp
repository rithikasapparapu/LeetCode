class Solution {
public:
    int getCellValue(int row, int col, vector<vector<int>>& grid) {
        return (row < 0 || col < 0 || row >= grid.size() || col >= grid[0].size()) ? 0 : grid[row][col];
    }

    int dfs(int row, int col, int islandId, vector<vector<int>>& grid) {
        if(row < 0 || col < 0 || row > grid.size()-1 || col > grid[0].size()-1 || grid[row][col] != 1) return 0;
        grid[row][col] = islandId;
        int val = 0;
        val += dfs(row + 1, col, islandId, grid);
        val += dfs(row - 1, col, islandId, grid);
        val += dfs(row, col + 1, islandId, grid);
        val += dfs(row, col - 1, islandId, grid);
        return 1 + val;
    }

    int largestIsland(vector<vector<int>>& grid) {
        vector<int> islandAreas = {0, 0};
        int maxIslandArea = 0;
        
        for (int row = 0; row < grid.size(); ++row) {
            for (int col = 0; col < grid[row].size(); ++col) {
                if (grid[row][col] == 1) {
                    islandAreas.push_back(dfs(row, col, islandAreas.size(), grid));
                }
            }
        }

        for (int row = 0; row < grid.size(); ++row) {
            for (int col = 0; col < grid[row].size(); ++col) {
                if (grid[row][col] == 0) {
                    unordered_set<int> adjacentIslands;
                    if(row+1 < grid.size()) adjacentIslands.insert(grid[row + 1][col]);
                    if(col+1 < grid[0].size()) adjacentIslands.insert(grid[row][col+1]);
                    if(row-1 >= 0) adjacentIslands.insert(grid[row - 1][col]);
                    if(col-1 >= 0) adjacentIslands.insert(grid[row][col - 1]);
                    int combinedArea = 1;
                    for (int island : adjacentIslands) {
                        combinedArea += islandAreas[island];
                    }
                    maxIslandArea = max(maxIslandArea, combinedArea);
                }
            }
        }

        if(maxIslandArea == 0) return grid.size() * grid[0].size();
        return  maxIslandArea;
    }
};
