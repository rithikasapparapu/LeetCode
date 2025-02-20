class Solution {
public:
    string btk(vector<string>& nums, string temp, int n){
        if(temp.size()==n){
            if(find(nums.begin(), nums.end(), temp) == nums.end()) return temp;
            return "";
        }
        string b;
        temp += "0";
        b = btk(nums, temp, n);
        if(b!="") return b;
        temp.pop_back();

        temp += "1";
        b = btk(nums, temp, n);
        if(b!="") return b;
        temp.pop_back();

        return "";
    }

    string findDifferentBinaryString(vector<string>& nums) {
        string temp = "";
        int n = nums.size();
        sort(nums.begin(), nums.end());
        string res = btk(nums, temp, n);
        return res;
    }
};