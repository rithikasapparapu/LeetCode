class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> dp(nums.size()+1);
        int max_val = INT_MIN;
        for(int i=0; i<nums.size(); i++){
            if(i==0){
                dp[i] = nums[i];
            }
            else{
                dp[i] = max(dp[i-1] + nums[i], nums[i]);
            }
            max_val = max(max_val, dp[i]);
        }
        return max_val;
    }
};