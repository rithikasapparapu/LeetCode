class Solution {
public:
    void permutation(int idx, vector<vector<int>>& result, vector<int>& nums){
        if(idx > nums.size()-1){
            result.push_back(nums);
        }
        for(int i=idx; i<nums.size(); i++){
            swap(nums[idx],nums[i]);
            permutation(idx+1,result,nums);
            swap(nums[i],nums[idx]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        permutation(0, result, nums);
        return result;
    }
};