class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> result;
        int i = 0, j = 0;
        while(i<m && j<n){
            if(nums1[i] < nums2[j]){
                result.push_back(nums1[i]);
                i++;
            }
            else if(nums1[i] > nums2[j]){
                result.push_back(nums2[j]);
                j++;
            }
            else{
                result.push_back(nums2[j]);
                result.push_back(nums1[i]);
                i++;
                j++;
            }
        }
        if(i==m){
            for(int t=j; t<n; t++){
                result.push_back(nums2[j]);
                j++;
            }
        }
        if(j==n){
            for(int t=i; t<m; t++){
                result.push_back(nums1[i]);
                i++;
            }
        }
        nums1 = result;
        return;
    }
};