class Solution {
public:
    int minimumLength(string s) {
        unordered_map <char, int> umap;
        for(int i=0; i<s.length(); i++){
            umap[s[i]]++;
        }
        int count = 0;
        for(auto it=umap.begin(); it!=umap.end(); it++){
            if(it->second % 2 == 0) count += 2;
            else count += 1;
        }
        return count;
    }
};