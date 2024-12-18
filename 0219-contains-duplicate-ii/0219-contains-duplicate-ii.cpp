class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        for(int i=0; i<nums.size(); i++){
            map[nums[i]]++;
        }
        int l=0;
        int r=l+1;
        while(l<nums.size()){
            while(l<nums.size() && map[nums[l]]==1)
                l++;
            r=l+1;
            while(r-l<=k && r<nums.size()){
                if(nums[r]==nums[l])
                    return true;
                r++;
            }
            l++;
        }
        return false;
    }
};