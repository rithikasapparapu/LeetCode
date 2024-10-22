class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        Arrays.sort(nums);
        List<List<Integer>> result= new ArrayList<>();
        for(int i=0; i<nums.length-2; i++){
            if(i>0 && nums[i]==nums[i-1]){
                continue;
            }
            int l = i+1;
            int r = nums.length-1;
            while(l<r){
                if(nums[i]+nums[l]+nums[r]==0){
                    //add to the list
                    result.add(Arrays.asList(nums[i],nums[l],nums[r]));
                    l++;
                    r--;
                    while(l<r && nums[l-1]==nums[l] && nums[r+1]==nums[r]){
                        l++;
                        r--;
                    }
                }
                else if(nums[i]+nums[l]+nums[r]<0){
                    l++;
                }
                else{
                    r--;
                }
            }
        }
        return result;
    }
}

/*
class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        Arrays.sort(nums);
        Set<List<Integer>> s = new HashSet<>();
        List<List<Integer>> result= new ArrayList<>();
        for(int i=0; i<nums.length-2; i++){
            int l = i+1;
            int r = nums.length-1;
            while(l<r){
                if(nums[i]+nums[l]+nums[r]==0){
                    //add to the list
                    s.add(Arrays.asList(nums[i],nums[l],nums[r]));
                    l++;
                    r--;
                }
                else if(nums[i]+nums[l]+nums[r]<0){
                    l++;
                }
                else{
                    r--;
                }
            }
        }
        result.addAll(s);
        return result;
    }
}
*/