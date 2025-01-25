class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        sort(horizontalCuts.begin(), horizontalCuts.end());
        horizontalCuts.push_back(h);
        int height = horizontalCuts[0];
        for(int i=1; i<horizontalCuts.size(); i++){
            height = max(height,horizontalCuts[i]-horizontalCuts[i-1]);
        }

        sort(verticalCuts.begin(), verticalCuts.end());
        verticalCuts.push_back(w);
        int width = verticalCuts[0];
        for(int j=1; j<verticalCuts.size(); j++){
            width = max(width,verticalCuts[j]-verticalCuts[j-1]);
        }
        long long result = (1LL * height % (1000000007) * width % 1000000007) % 1000000007;
        return result;
    }
};