class Solution {
    public int removeDuplicates(int[] nums) {
        int len = nums.length;
        if(len == 0){
            return 0;
        }
        if(len == 1){
            return 1;
        }
        int l = 1;
        int r = 1;
        int count = 1;
        while(r<len){
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