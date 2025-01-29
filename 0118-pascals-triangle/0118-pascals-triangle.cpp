class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        vector<int> first(1,1);
        result.push_back(first);
        for(int i=2; i<=numRows; i++){
            vector<int> entry(i,1);
            for(int j=1; j<i-1; j++){
                entry[j] = result.back()[j-1] + result.back()[j];
            }
            result.push_back(entry);
        }
        return result;
    }
};