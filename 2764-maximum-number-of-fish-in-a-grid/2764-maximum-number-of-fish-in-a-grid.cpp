class Solution {
public:
    int dfs(int row, int col, vector<vector<int>>& grid, int rows, int cols){
        if(row<0 || col<0 || row>rows-1 || col>cols-1 || grid[row][col]==0)
            return 0;
        int val = grid[row][col];
        grid[row][col] = 0;
        val += dfs(row+1,col,grid,rows,cols);
        val += dfs(row,col+1,grid,rows,cols);
        val += dfs(row-1,col,grid,rows,cols);
        val += dfs(row,col-1,grid,rows,cols);
        return val;
    }
    int findMaxFish(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int val = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]!=0){
                    val = max(val, dfs(i,j,grid,m,n));
                }
            }
        }
        return val;
    }
};