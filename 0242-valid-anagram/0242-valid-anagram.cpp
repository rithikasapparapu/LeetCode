class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length()) return false;
        unordered_map<char,int> mp;
        for(int i=0; i<s.length(); i++){
            mp[s[i]]++;
        }
        for(int i=0; i<t.length(); i++){
            if(mp.count(t[i])==0){
                return false;
            }
            else{
                if(mp[t[i]]==0) return false;
                mp[t[i]]--;
            }
        }
        return true;
    }
};