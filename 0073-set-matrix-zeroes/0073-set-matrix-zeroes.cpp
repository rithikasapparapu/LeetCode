class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        unordered_set <int> i_s;
        unordered_set <int> j_s;
        int m = matrix.size();
        int n = matrix[0].size();
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(matrix[i][j]==0){
                    i_s.insert(i);
                    j_s.insert(j);
                }
            }
        }
        for(auto itr : i_s){
            for(int j=0; j<n; j++){
                matrix[itr][j] = 0;
            }
        }

        for(auto itr : j_s){
            for(int i=0; i<m; i++){
                matrix[i][itr] = 0;
            }
        }
    }
};