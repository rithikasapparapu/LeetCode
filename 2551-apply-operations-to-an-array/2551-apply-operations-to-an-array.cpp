class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        for(int i=0; i<nums.size()-1; i++){
            if(nums[i]==nums[i+1]){
                nums[i] *= 2;
                nums[i+1] = 0;
            }
        }
        int t = 0, j = 0;
        while(j < nums.size()) {
            if(nums[j] != 0) {
                nums[t] = nums[j];
                t++;
            }
            j++;
        }
        while(t < nums.size()) {
            nums[t] = 0;
            t++;
        }
        
        return nums;
    }
};