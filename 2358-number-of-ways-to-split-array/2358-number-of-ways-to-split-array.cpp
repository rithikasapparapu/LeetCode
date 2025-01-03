class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long sum = 0;
        for(int i=0; i<nums.size(); i++){
            sum += nums[i];
        }
        int result = 0;
        long long prefix_sum = 0;
        for(int i=0; i<nums.size()-1; i++){
            prefix_sum += nums[i];
            if(prefix_sum >= sum - prefix_sum){
                result++;
            }
        }
        return result;
    }
};