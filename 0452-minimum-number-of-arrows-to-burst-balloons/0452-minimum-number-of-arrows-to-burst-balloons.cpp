class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        vector<vector<int>> result;
        sort(points.begin(), points.end());
        result.push_back(points[0]);
        for(int i=1; i<points.size(); i++){
            if(points[i][0]<=result.back()[1]){
                result.back()[0] = max(points[i][0],result.back()[0]);
                result.back()[1] = min(points[i][1],result.back()[1]);
            }
            else{
                result.push_back(points[i]);
            }
        }
        return result.size();
    }
};