class Solution {
public:
    bool isPrefixAndSuffix(string first, string second){
        if(second.substr(0,first.length())==first && second.substr(second.length()-first.length(),first.length())==first){
            return true;
        }
        return false;
    }
    int countPrefixSuffixPairs(vector<string>& words) {
        int count = 0;
        for(int i=0; i<words.size(); i++){
            for(int j=i+1; j<words.size(); j++){
                if(isPrefixAndSuffix(words[i], words[j]))
                    count++;
            }
        }
        return count;
    }
};