class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        unordered_set <char> vowels = {'a', 'e', 'i', 'o', 'u'};
        vector <int> ans;
        vector <int> words_prefix;
        int cum_sum = 0;
        for(int i=0; i<words.size(); i++){
            if(vowels.find(words[i][0])!=vowels.end() && vowels.find(words[i][words[i].length()-1])!=vowels.end()){
                cum_sum += 1;
            }
            words_prefix.push_back(cum_sum);
        }
        int count = 0;
        for(vector<int> query:queries){
            if(vowels.find(words[query[0]][0])!=vowels.end() && vowels.find(words[query[0]][words[query[0]].length()-1])!=vowels.end()){
                count = words_prefix[query[1]] - words_prefix[query[0]] + 1;
            }
            else{
                count = words_prefix[query[1]] - words_prefix[query[0]];
            }

            ans.push_back(count);
        }
        return ans;
    }
};