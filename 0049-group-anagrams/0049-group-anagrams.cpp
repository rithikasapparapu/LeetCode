class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        unordered_map <string, vector<string>> map;
        for(int i=0; i<strs.size(); i++){
            string temp = strs[i];
            sort(temp.begin(),temp.end());
            map[temp].push_back(strs[i]);
        }
        for(auto e:map){
            result.push_back(e.second);
        }
        return result;
    }
};