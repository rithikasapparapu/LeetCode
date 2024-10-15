class Solution {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
        int i=0;
        int j=0;
        int k=0;
        int[] result = new int[m+n];
        if(n==0){
            return;
        }
        if(m==0){
            for(int y=0; y<m+n; y++){
                nums1[y] = nums2[y];
            }
            return;
        }
        while(i<m && j<n){
            if(nums1[i] <= nums2[j]){
                result[k] = nums1[i];
                i++;
            }
            else{
                result[k] = nums2[j];
                j++;
            }
            k++;
        }
        if(i==m){
            for(int t=j; t<n; t++){
                result[k] = nums2[t];
                k++;
            }
        }
        if(j==n){
           for(int t=i; t<m; t++){
                result[k] = nums1[t];
                k++;
            } 
        }
        for(int y=0; y<m+n; y++){
            nums1[y] = result[y];
        }
        return;
    }
}