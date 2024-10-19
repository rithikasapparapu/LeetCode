class Solution {
    public int removeDuplicates(int[] nums) {
        if(nums.length == 0){
            return 0;
        }
        if(nums.length == 1){
            return 1;
        }
        int l = 1;
        int r = 1;
        int count = 1;
        while(r<nums.length){
            if(nums[r]==nums[r-1]){
                count++;
                if(count<=2){
                    nums[l] = nums[r];
                    l++;
                }
            }
            else{
                count = 1;
                nums[l] = nums[r];
                l++; 
            }
            r++;
        }
        return l;
    }
}