class Solution {
public:
    bool f(vector<int>& result, vector<bool> visited, int idx, int n){
        if(idx == result.size()) return true;

        if(result[idx]!=0) return f(result, visited, idx+1, n);

        for(int val=n; val>=1; val--){
            int nextIdx = (val == 1) ? idx : idx + val;
            if(visited[val] || (val > 1 && (nextIdx >= result.size() || result[nextIdx]!=0))) continue;
            result[idx] = val;
            result[nextIdx] = val;
            visited[val] = true;
            if(f(result, visited, idx+1, n)) return true;
            result[idx] = 0;
            result[nextIdx] = 0;
            visited[val] = false;
        }
        return false;
    }
    vector<int> constructDistancedSequence(int n){
        int len = (n*2) - 1;
        vector<int>result(len,0);
        vector<bool> visited(n+1,0);
        f(result, visited, 0, n);
        return result;
    }
};