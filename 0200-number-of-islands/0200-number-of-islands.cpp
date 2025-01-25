class Solution {
public:
    void dfs(int currow, int curcol, vector<vector<char>>& grid, int rows, int cols){
        vector <int> dx = {-1,0,1,0};
        vector <int> dy = {0,1,0,-1};
        grid[currow][curcol] = '0';
        for(int d=0; d<4; d++){
            if(currow+dx[d]<0 || curcol+dy[d]<0 || currow+dx[d]>rows-1 || curcol+dy[d]>cols-1 || grid[currow+dx[d]][curcol+dy[d]]=='0') continue;
            dfs(currow+dx[d],curcol+dy[d],grid,rows,cols);
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]!='0'){
                    count++;
                    dfs(i, j, grid, m, n);
                }
            }
        }
        return count;
    }
};