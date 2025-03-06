class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> res(n*n, 0);
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                res[grid[i][j]-1]++;
            }
        }
        vector<int> result(2,0);
        for(int i=0; i<n*n; i++){
            if(res[i]==2) result[0] = i+1;
            else if(res[i]==0) result[1] = i+1;
        }
        return result;
    }
};