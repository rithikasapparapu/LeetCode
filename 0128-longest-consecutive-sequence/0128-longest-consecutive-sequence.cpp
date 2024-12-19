class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map <int,int> map;
        for(int i=0; i<nums.size(); i++){
            map[nums[i]]++;
        }
        if(nums.size()==0)
            return 0;
        int max_count = INT_MIN;
        int count = 0;
        for(int i=0; i<nums.size(); i++){
            if(map.count(nums[i]-1)==0){ //it is the first element of the sequence
                int temp = nums[i]+1;
                count = 1;
                while(map.count(temp)!=0){
                    count++;
                    temp++;
                }
                if(count>max_count)
                    max_count = count;
            }
        }
        return max_count; 
    }
};