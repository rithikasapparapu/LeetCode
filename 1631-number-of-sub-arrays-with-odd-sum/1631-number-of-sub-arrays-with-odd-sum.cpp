class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        const int MOD = 1000000007;
        vector<int>dp(arr.size());
        dp[0] = (arr[0]%2==0) ? 0 : 1;
        long long sum = dp[0];
        for(int i=1; i<dp.size(); i++){
            if(arr[i]%2==0) dp[i] = dp[i-1];
            else dp[i] = i + 1 - dp[i-1];
            sum = (sum + dp[i]) % MOD;
        }
        return sum;
    }
};