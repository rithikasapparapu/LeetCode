class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n = colors.size();
        if (k < 3) return 0;
        int L = k - 2;
        
        vector<bool> is_valley(n, false);
        for (int i = 0; i < n; ++i) {
            int prev = colors[(i - 1 + n) % n];
            int next = colors[(i + 1) % n];
            if (colors[i] != prev && colors[i] != next) {
                is_valley[i] = true;
            }
        }
        
        vector<int> prefix(2 * n + 1, 0);
        for (int i = 0; i < 2 * n; ++i) {
            int idx = i % n;
            prefix[i + 1] = prefix[i] + (is_valley[idx] ? 1 : 0);
        }
        
        int res = 0;
        for (int s = 0; s < n; ++s) {
            int start = s + 1;
            int end = start + L - 1;
            if (end >= 2 * n) continue;
            int sum = prefix[end + 1] - prefix[start];
            if (sum == L) {
                res++;
            }
        }
        return res;
    }
};
