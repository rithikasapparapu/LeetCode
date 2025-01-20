class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        
        unordered_map<int, pair<int, int>> pos_map;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                pos_map[mat[i][j]] = {i, j};
            }
        }
        
        vector<int> row_freq(m, 0);
        vector<int> col_freq(n, 0);
        
        for (int i = 0; i < arr.size(); i++) {
            int value = arr[i];
            auto [row, col] = pos_map[value];
            
            row_freq[row]++;
            col_freq[col]++;
            
            if (row_freq[row] == n || col_freq[col] == m) {
                return i;
            }
        }
        
        return -1;
    }
};