class Solution {
    public int removeElement(int[] nums, int val) {
        int len = nums.length;
        int[] result = new int[len];
        int k=0;
        for(int i=0; i<nums.length; i++){
            if(nums[i]==val){
                continue;
            }
            result[k] = nums[i];
            k++;
        }
        for(int i=0; i<k; i++){
            nums[i] = result[i];
        }
        return k;
    }
}