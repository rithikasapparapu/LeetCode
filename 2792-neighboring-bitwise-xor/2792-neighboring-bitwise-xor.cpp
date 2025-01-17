class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        // vector<int> pos1;
        // vector<int> pos2;
        // pos1.push_back(0);
        // pos2.push_back(1);
        // for(int i=0; i<derived.size()-1; i++){
        //     if(derived[i]==0){
        //         if(pos1[i]==0) pos1.push_back(0);
        //         else pos1.push_back(1);
        //         if(pos2[i]==1) pos2.push_back(1);
        //         else pos2.push_back(0);
        //     }
        //     else{
        //         if(pos1[i]==0) pos1.push_back(1);
        //         else pos1.push_back(0);
        //         if(pos2[i]==1) pos2.push_back(0);
        //         else pos2.push_back(1);
        //     }
        // }
        // if(pos1[pos1.size()-1] ^ pos1[0] != derived[derived.size()-1]) return false;
        // if(pos2[pos2.size()-1] ^ pos2[0] != derived[derived.size()-1]) return false;
        // return true;
        int res = 0;
        for(int i=0; i<derived.size(); i++){
            res ^= derived[i];
        }
        if(res == 0) return true;
        return false;
    }
};