class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector <int> prev (1,1);
        for(int i=1; i<=rowIndex; i++){
            vector <int> currow (i+1,1);
            for(int j=1; j<currow.size()-1; j++){
                currow[j] = prev[j-1] + prev[j];
            }
            prev = currow;
        }
        return prev;
    }
};