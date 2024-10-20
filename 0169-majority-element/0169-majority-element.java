class Solution {
    public int majorityElement(int[] nums) {
        Arrays.sort(nums);
        int count = 1;
        for(int i=1; i<nums.length; i++){
            if(nums[i]==nums[i-1]){
                count++;
            }
            else{
                if(count>nums.length/2){
                    return nums[i-1];
                }
                count = 1;
            }
        }
        return nums[nums.length-1];
    }
}