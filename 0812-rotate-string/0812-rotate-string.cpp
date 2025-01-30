class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s == goal) return true;
        for(int i=0; i<s.length()-1; i++){
            s = s + s[0];
            s = s.substr(1);
            if(s == goal) return true;
        }
        return false;
    }
};