class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, int> mp;
        int maxx = 0;
        vector<vector<int>>dp(n, vector<int>(n,2));
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if(mp.find(arr[j]-arr[i])!=mp.end()){
                    int k = mp[arr[j]-arr[i]];
                    dp[i][j] = dp[k][i] + 1;
                }
                maxx = max(maxx, dp[i][j]);
            }
            mp[arr[i]] = i;
        }
        if(maxx == 2) return 0;
        return maxx;
    }
};