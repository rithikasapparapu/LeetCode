class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        int i = 0, j = 0;
        vector<vector<int>> result;
        vector<int> res;
        while(i < nums1.size() && j < nums2.size()){
            if(nums1[i][0]==nums2[j][0]){
                res = {nums1[i][0], nums1[i][1]+nums2[j][1]};
                j++;
                i++;
            }
            else if(nums1[i][0]<nums2[j][0]){
                res = {nums1[i][0], nums1[i][1]};
                i++;
            }
            else{
                res = {nums2[j][0], nums2[j][1]};
                j++;
            }
            result.push_back(res);
        }
        while(i < nums1.size()){
            res = {nums1[i][0], nums1[i][1]};
            i++;
            result.push_back(res);
        }
        while(j < nums2.size()){
            res = {nums2[j][0], nums2[j][1]};
            j++;
            result.push_back(res);
        }
        return result;
    }
};