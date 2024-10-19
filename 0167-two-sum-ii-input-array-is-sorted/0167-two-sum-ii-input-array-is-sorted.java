class Solution {
    public int[] twoSum(int[] numbers, int target) {
        int l=0;
        int r=numbers.length-1;
        int[] result = {0,0};
        while(l<r){
            if(numbers[l]+numbers[r]==target){
                result[0]=l+1;
                result[1]=r+1;
                return result;
            }
            else if(numbers[l]+numbers[r]>target){
                r--;
            }
            else{
                l++;
            }
        }
    return result;
    }
}