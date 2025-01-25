class Solution { 
public:
    vector<int> lexicographicallySmallestArray(vector<int>& arr, int limit) {
        int len = arr.size();
        
        vector<pair<int,int>> sortedArr;
        for(int i = 0; i < len; ++i)
            sortedArr.push_back(make_pair(arr[i], i));
        
        sort(sortedArr.begin(), sortedArr.end());

        int start = 0, end = 1;
        while (end < len) {
            vector<int> indices = {sortedArr[start].second};
            while (end < len && abs(sortedArr[end].first - sortedArr[end - 1].first) <= limit) {
                indices.push_back(sortedArr[end].second);
                end++;
            }

            sort(indices.begin(), indices.end());

            for (int i = 0; i < end - start; ++i)
                arr[indices[i]] = sortedArr[start + i].first;
            
            start = end;
            end++;
        }
        return arr;
    }
};
