class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int r = 1;
        int count = 1;
        int maxi = 1;
        while(r < nums.size()){
            if(nums[r] > nums[r-1]){
                count = 1;
                while(r < nums.size() && nums[r] > nums[r-1]){
                    r++;
                    count++;
                }
                maxi = max(maxi, count);
            }
            else if(nums[r] < nums[r-1]){
                count = 1;
                while(r < nums.size() && nums[r] < nums[r-1]){
                    r++;
                    count++;
                }
                maxi = max(maxi, count);
            }
            else{
                r++;
            }
        }
        return maxi;
    }
};