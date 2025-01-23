class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        set <pair<int,int>> s;
        int rows = grid.size();
        int cols = grid[0].size();
        //parse rows
        for(int i=0; i<rows; i++){
            int count = 0;
            for(int j=0; j<cols; j++){
                if(grid[i][j]==1){
                    count++;
                    if(count>1) break;
                }
            }
            if(count > 1){
                for(int j=0; j<cols; j++){
                    if(grid[i][j]==1){
                        s.insert(make_pair(i,j));
                    }
                }
            }
        }
        //parse columns
        for(int j=0; j<cols; j++){
            int count = 0;
            for(int i=0; i<rows; i++){
                if(grid[i][j]==1){
                    count++;
                    if(count>1) break;
                }
            }
            if(count > 1){
                for(int i=0; i<rows; i++){
                    if(grid[i][j]==1){
                        s.insert(make_pair(i,j));
                    }
                }
            }
        }
        return s.size();
    }
};