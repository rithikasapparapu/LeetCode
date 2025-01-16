class Solution {
public:
    int xorArray(vector<int>& nums){
        int res = 0; 
        for(int i=0; i<nums.size(); i++){
            res ^= nums[i];
        }
        return res;
    }
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        if(n1%2==0 && n2%2==0)
            return 0;
        else if(n1%2!=0 && n2%2==0){
            return xorArray(nums2);
        }
        else if(n2%2!=0 && n1%2==0){
            return xorArray(nums1);
        }
        return xorArray(nums1) ^ xorArray(nums2); 
    }
};