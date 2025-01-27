class Solution {
public:
    void combination(int idx, int target, vector<int>& stack, vector<int>& candidates, vector<vector<int>>& result){
        if(idx==candidates.size()){
            if(target==0) result.push_back(stack);
            return;
        }
        if(target-candidates[idx]>=0){
            stack.push_back(candidates[idx]);
            combination(idx,target-candidates[idx], stack, candidates, result);
            stack.pop_back();
        }
        combination(idx+1, target, stack, candidates, result);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> stack;
        combination(0, target, stack, candidates, result);
        return result;
    }
};