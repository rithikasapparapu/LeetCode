class Solution {
public:
    bool overlap(vector<int>& a, vector<int>& b){
        int smaller = max(a[0],b[0]);
        int larger = min(a[1],b[1]);
        if(larger-smaller>=0)
            return true;
        return false;
    }

    vector<int> merge(vector<int>& a, vector<int>& b){
        vector<int> res;
        res.push_back(min(a[0],b[0]));
        res.push_back(max(a[1],b[1]));
        return res;
    }

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> result;
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b){
            return a[0] < b[0];
        });
        result.push_back(intervals[0]);
        for(int i=1; i<intervals.size(); i++){
            if (overlap(result.back(),intervals[i])){
                vector<int> merged_interval = merge(result.back(),intervals[i]);
                result[result.size()-1] = merged_interval;
            }
            else{
                result.push_back(intervals[i]);
            }
        }
        return result;
    }
};