class Solution {
    public int maxArea(int[] height) {
        int l = 0;
        int r = height.length - 1;
        int volume = 0;
        while(l<r){
            if(volume < (r-l) * Math.min(height[r],height[l])){
                volume = (r-l) * Math.min(height[r],height[l]);
            }
            if(height[l]==height[r]){
                l++;
                r--;
            }
            else if(height[l]<height[r]){
                l++;
            }
            else{
                r--;
            }
        }
        return volume;
    }
}