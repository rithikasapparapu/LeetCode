class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        long long lsum = 0, rsum = 0;
        for(int i=1; i<nums.size(); i++){
            rsum += nums[i];
        }
        if(lsum == rsum) return 0;
        for(int i=1; i<nums.size(); i++){
            lsum += nums[i-1];
            rsum -= nums[i];
            if(lsum == rsum) return i;
        }
        return -1;
    }
};