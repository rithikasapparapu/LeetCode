class Solution {
public:
    int countPalindromicSubsequence(string s) {
        unordered_set <char> letters;

        for(char letter:s){
            letters.insert(letter);
        }
        int result = 0;
        for(char letter:letters){
            int i = -1, j = 0;
            for(int k=0; k<s.size(); k++){
                if(i==-1 && s[k] == letter){
                    i = k;
                }
                if(s[k] == letter){
                    j = k;
                }
            }
            unordered_set <char> between;
            for(int k=i+1; k<j; k++){
                between.insert(s[k]);
            }
            result += between.size();
        }
        return result;
    }
};