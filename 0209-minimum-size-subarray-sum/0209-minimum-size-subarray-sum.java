class Solution {
    public int minSubArrayLen(int target, int[] nums) {
        int l = 0;
        int r = 0;
        if(nums.length==0){
            return 0;
        }
        int sum = nums[l];
        int result = Integer.MAX_VALUE;
        while(l<=r && r<nums.length){
            if(sum >= target){
                if(result>r-l+1){
                    result = r-l+1;
                }
                sum -= nums[l];
                l++;
            }
            else{
                r++;
                if(r<nums.length){
                    sum += nums[r];
                }
            }
        }
        if(result == Integer.MAX_VALUE){
            return 0;
        }
        return result;
    }
}

//Time Limit Exceed Error
/*
//solution 1:
class Solution {
    public int minSubArrayLen(int target, int[] nums) {
        int outer_sum = 0;
        int inner_sum=0;
        int win_len = 1;
        while(win_len<=nums.length){
            outer_sum += nums[win_len-1];
            inner_sum = outer_sum;
            if(inner_sum>=target){
                return win_len;
            }
            for(int i=1; i<(nums.length-win_len+1); i++){
                inner_sum = inner_sum - nums[i-1] + nums[i+win_len-1];
                if(inner_sum>=target){
                    return win_len;
                }
            }
            win_len++;
        }
        return 0;
    }
}


//solution 2:
class Solution {
    public int minSubArrayLen(int target, int[] nums) {
        int sum;
        int result = Integer.MAX_VALUE;
        for(int i=0; i<nums.length; i++){
            sum = 0;
            for(int j=i; j<nums.length; j++){
                sum += nums[j];
                if(sum>=target){
                    if(result>j-i+1){
                        result = j-i+1;
                    }
                    break;
                }
            }
        }
        if(result==Integer.MAX_VALUE){
            return 0;
        }
        return result;
    }
}
*/