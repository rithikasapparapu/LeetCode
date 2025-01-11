class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string> result;
        unordered_map <char, int> map;
        for(int j=0; j<words2.size(); j++){
            unordered_map <char,int> current;
            for(int k=0; k<words2[j].length(); k++){
                current[words2[j][k]]++;
            }
            for(auto it=current.begin(); it!=current.end(); it++){
                if(map.find(it->first)==map.end()){
                    map[it->first] = current[it->first];
                }
                else{
                    if(current[it->first]>=map[it->first])
                        map[it->first] = current[it->first];
                }
            }
        }
        for(auto i=map.begin(); i!=map.end(); i++){
            cout << "print " << i->first << " " << i->second << endl;
        }
        for(int i=0; i<words1.size(); i++){
            unordered_map <char, int> map_copy;
            map_copy = map;
            for(int k=0; k<words1[i].length(); k++){
                if(map_copy.find(words1[i][k])!=map_copy.end()){
                    cout << "printing " << map_copy[words1[i][k]] << endl;
                    if(map_copy[words1[i][k]]>0)
                        map_copy[words1[i][k]]--;
                }
            }

            bool issubset = true;
            for(auto i=map_copy.begin(); i!=map_copy.end(); i++){
                cout << "i->second" << i->second << endl;
                if (i->second != 0){
                    issubset = false;
                }
            }

            if(issubset)
                result.push_back(words1[i]);
        }
        return result;
    }
};