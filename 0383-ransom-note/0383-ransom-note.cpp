class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int> umap;
        for(int i=0; i<magazine.length(); i++){
            umap[magazine[i]]++;
        }
        for(int i=0; i<ransomNote.length(); i++){
            if(umap.find(ransomNote[i])!=umap.end()){
                if(umap[ransomNote[i]]==0)
                    return false;
                else
                   umap[ransomNote[i]]--; 
            }
            else
                return false;
        }
        return true;
    }
};