class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.length()!=t.length())
            return false;
        unordered_map<char,char> m;
        unordered_map<char,int> t_strings;
        for(int i=0; i<s.length(); i++){
            if(m.find(s[i])==m.end()){
                if(t_strings.find(t[i])!=t_strings.end())
                    return false;
                m[s[i]]=t[i];
                t_strings[t[i]]++;
            }
            else{
                if(m[s[i]]!=t[i])
                    return false;
            }
        }
        return true;
    }
};