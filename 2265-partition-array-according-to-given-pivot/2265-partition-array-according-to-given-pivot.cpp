class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int count = 0;
        vector<int> res;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]<pivot){
                res.push_back(nums[i]);
            }
            else if(nums[i]==pivot) count++;
            else continue;
        }
        while(count > 0){
            res.push_back(pivot);
            count--;
        }
        for(int i=0; i<nums.size(); i++){
            if(nums[i]>pivot){
                res.push_back(nums[i]);
            }
        }
        return res;
    }
};