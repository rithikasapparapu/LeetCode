class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if(nums.size()==1) return;
        int n = nums.size();
        int right=n-1, left=n-2;
        while(left>=0){
            if(nums[left]>=nums[left+1]){
                left--;
            }
            else{
                if(nums[left]>=nums[right]) right--;
                else{
                    swap(nums[left], nums[right]);
                    break;
                }
            }
        }
        sort(nums.begin()+left+1,nums.end());
        return;
    }
};