class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> words;
        int start = 0;
        int end = 0;
        for(int i=0; i<s.length(); i++){
            if(s[i]==' '){
                end = i;
                words.push_back(s.substr(start,end-start));
                start=end+1;
            }
        }
        words.push_back(s.substr(end+1,s.length()-end));
        if(pattern.length()!=words.size())
            return false;
        unordered_map <char,string> map;
        unordered_set <string> set;
        for(int i=0; i<pattern.length(); i++){
            if(map.count(pattern[i])==0){
                if(set.count(words[i])==0){
                    map[pattern[i]]=words[i];
                    set.insert(words[i]);
                }
                else
                    return false;
            }
            else{
                if(map[pattern[i]]!=words[i])
                    return false;
            }
        }
        return true;
    }
};