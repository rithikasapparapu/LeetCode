class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        unordered_set<string> output;
        for(int i=0; i<words.size(); i++){
            for(int j=i+1; j<words.size(); j++){
                if(words[i].contains(words[j])) output.insert(words[j]);
                else if(words[j].contains(words[i])) output.insert(words[i]);
            }
        }
        vector <string> result;
        for(auto val:output){
            result.push_back(val);
        }
        return result;
    }
};