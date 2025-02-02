class Solution {
public:
    bool check(vector<int>& nums) {
        int drops = 0;
        int n = nums.size();
        for(int i=1; i<n; i++){
            if(nums[i]<nums[i-1]) drops++;
        }
        if(nums[0]<nums[n-1]) drops++;
        if(drops <= 1) return true;
        return false;
    }
};