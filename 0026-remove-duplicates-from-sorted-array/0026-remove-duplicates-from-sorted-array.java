class Solution {
    public int removeDuplicates(int[] nums) {
        if(nums.length==0){
            return 0;
        }
        if(nums.length==1){
            return 1;
        }
        int k = 1;
        int[] result = new int[nums.length];
        result[0] = nums[0];
        if(nums[0]!=nums[1]){
            result[1] = nums[1];
            k++;
        }
        if(nums.length==2){
            return k;
        }
        for(int i=1; i<nums.length-1; i++){
            if(nums[i]!=nums[i+1]){
                result[k] = nums[i+1];
                k++;
            }
        }
        for(int i=0; i<result.length; i++){
            nums[i] = result[i];
        }
        return k;
    }
}