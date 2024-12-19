class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        unordered_map <int,int> map;
        for(int i=0; i<nums.size(); i++){
            map[nums[i]]++;
        }
        for(int i=0; i<nums.size(); i++){
            if(map.count(target-nums[i])!=0)
                if(target-nums[i]!=nums[i] )
                    result.push_back(i);
                else{
                    if(map[target-nums[i]]>1){
                        result.push_back(i);
                    }
                }
        }
        return result;
    }
};