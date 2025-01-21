class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int n = grid[0].size();
        long long sum1 = 0;
        for(int i=0; i<n; i++){
            sum1 += grid[0][i];
        }
        long long min_val = LLONG_MAX, right_sum = sum1, left_sum = 0;
        for(int i=0; i<n; i++){
            right_sum -= grid[0][i];
            if(i>0) left_sum += grid[1][i-1];
            if(min_val > max(left_sum, right_sum)) min_val = max(left_sum, right_sum);
        }
        return min_val;
    }
};