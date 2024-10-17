class Solution {
    public void rotate_by_one_step(int[] num){
        int last = num[num.length - 1];
        for(int i=num.length-2; i>=0; i--){
            num[i+1] = num[i];
        }
        num[0] = last;
    }

    public void rotate(int[] nums, int k) {
        k = k % nums.length;
        int[] result = new int[nums.length];
        // while(k>0){
        //     rotate_by_one_step(nums);
        //     k--;
        // }
        int i = 0;
        for(int j=nums.length-k; j<nums.length; j++){
            result[i] = nums[j];
            i++;
        }
        for(int j=0; j<nums.length-k; j++){
            result[i] = nums[j]; 
            i++;
        }
        for(int j=0; j<nums.length; j++){
            nums[j] = result[j];
        }
    }
}