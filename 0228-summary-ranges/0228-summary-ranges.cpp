class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> result;
        if(nums.size()==0)
            return result;
        string res = "";
        int start = nums[0];
        int end = nums[0];
        for(int i=1; i<nums.size(); i++){
            if(nums[i]-1==nums[i-1]){
                end = nums[i];
            }
            else{
                if(start==end)
                    res = res + to_string(start);
                else
                    res = res + to_string(start) + "->" + to_string(end);
                result.push_back(res);
                start = nums[i];
                end = nums[i];
                res = "";
            }
        }
        if(start==end)
            res = res + to_string(start);
        else
            res = res + to_string(start) + "->" + to_string(end);
        result.push_back(res);
        return result;
    }
};