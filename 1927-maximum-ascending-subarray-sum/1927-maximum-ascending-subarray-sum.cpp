class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int maxx = nums[0];
        int asc = false;
        int res = nums[0];
        for(int i=1; i<nums.size(); i++){
            if(nums[i-1] < nums[i]) asc = true;
            else asc = false;
            if(asc) res += nums[i];
            else{
                maxx = max(maxx, res);
                res = nums[i];
            }
        }
        maxx = max(maxx, res);
        return maxx;
    }
};