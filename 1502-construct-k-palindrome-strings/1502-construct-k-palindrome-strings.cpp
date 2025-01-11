class Solution {
public:
    bool canConstruct(string s, int k) {
        //at most k single letters and all other letters frequency nust be divisible by 2.
        unordered_map <char, int> umap;
        if(s.length()<k)
            return false;
        for(int i=0; i<s.length(); i++){
            umap[s[i]]++;
        }
        int singles = 0;
        for(auto it=umap.begin(); it!=umap.end(); it++){
            cout << it->second << " " << endl;
            if(it->second % 2 != 0)
                singles++;
        }
        if(singles>k){
            cout << "hi";
            return false;
        }
        return true;
    }    
};