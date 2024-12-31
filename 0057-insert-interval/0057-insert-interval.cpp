class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> result;
        int start=newInterval[0];
        int end=newInterval[1];
        // if(intervals.size()==0){
        //     result.push_back(newInterval);
        //     return result;
        // }
        bool start_found = false;
        bool end_found = false;
        for(int i=0; i<intervals.size(); i++){
            if(!start_found){
                if(newInterval[0]<intervals[i][0]){
                    start_found = true;
                    start = newInterval[0];
                }
                else if(newInterval[0]>intervals[i][1]){
                    result.push_back(intervals[i]);
                }
                else{
                    start_found = true;
                    start = intervals[i][0];
                }
            }
            else {
                if(!end_found){
                    if(newInterval[1]<intervals[i][0]){
                        end_found = true;
                        if(newInterval[1]<intervals[i-1][0]){
                            end = newInterval[1];
                            vector<int> r1;
                            r1.push_back(start);
                            r1.push_back(end);
                            result.push_back(r1);
                            result.push_back(intervals[i-1]);
                            result.push_back(intervals[i]);
                        }
                        else if(newInterval[1]>intervals[i-1][1]){
                            end = newInterval[1];
                            vector<int> r1;
                            r1.push_back(start);
                            r1.push_back(end);
                            result.push_back(r1);
                            result.push_back(intervals[i]);
                        }
                        else{
                            end = intervals[i-1][1];
                            vector<int> r1;
                            r1.push_back(start);
                            r1.push_back(end);
                            result.push_back(r1);
                            result.push_back(intervals[i]);
                        }
                    }
                    else if(newInterval[1]>intervals[i][1]){
                        continue;
                    }
                    else{
                        end_found = true;
                        end = intervals[i][1];
                        vector<int> r1;
                        r1.push_back(start);
                        r1.push_back(end);
                        result.push_back(r1);
                    }
                }
                else{
                    result.push_back(intervals[i]);
                }
            }
        }
        if(!start_found){
            result.push_back(newInterval);
        }
        if(start_found && !end_found){
            if(newInterval[1]<intervals[intervals.size()-1][0]){
                vector<int> r;
                r.push_back(start);
                r.push_back(newInterval[1]);
                result.push_back(r);
                result.push_back(intervals[intervals.size()-1]);
            }
            else if(newInterval[1]>intervals[intervals.size()-1][1]){
                vector<int> r;
                r.push_back(start);
                r.push_back(newInterval[1]);
                result.push_back(r);
            }
            else{
                vector<int> r;
                r.push_back(start);
                r.push_back(intervals[intervals.size()-1][1]);
                result.push_back(r);
            }
        }
        return result;
    }
};