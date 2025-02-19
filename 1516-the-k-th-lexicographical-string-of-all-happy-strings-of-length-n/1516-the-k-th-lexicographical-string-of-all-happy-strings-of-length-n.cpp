class Solution {
public:
    bool btk(vector<string>& res, string temp, int n, int k, string happy){
        if(temp.length()==n){
            res.push_back(temp);
            if(res.size()==k){
                return true;
            }
            return false;
        }
        bool b;
        for(int i=0; i<happy.length(); i++){
            if(temp.empty()){
                temp += happy[i];
                b = btk(res, temp, n, k, happy);
                if(b) return true;
                temp.pop_back();
            }
            else{
                if(happy[i]!=temp.back()){
                    temp += happy[i];
                    b = btk(res, temp, n, k, happy);
                    if(b) return true;
                    temp.pop_back();
                }
            }
        }
        return false;
    }
    string getHappyString(int n, int k) {
        vector<string> res;
        string temp = "";
        string happy = "abc";
        if (!btk(res, temp, n, k, happy)) return "";
        else return res.back();
    }
};