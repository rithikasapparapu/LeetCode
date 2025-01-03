class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int result = 0;
        long long right_sum = 0;
        long long left_sum = nums[0];
        for(int i=1; i<nums.size(); i++){
            right_sum += nums[i];
        }
        for(int i=0; i<nums.size()-1; i++){
            if(left_sum >= right_sum){
                result++;
            }
            left_sum += nums[i+1];
            right_sum -= nums[i+1];
        }
        return result;
    }
};