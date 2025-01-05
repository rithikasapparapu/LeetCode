class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.length();
        vector<int> diff(n + 1, 0);

        for (auto& shift : shifts) {
            int start = shift[0], end = shift[1], direction = shift[2];
            if (direction == 1) {
                diff[start]++;
                if (end + 1 < n) diff[end + 1]--;
            } 
            else{
                diff[start]--;
                if (end + 1 < n) diff[end + 1]++;
            }
        }


        int cumulative_shift = 0;
        for(int i=0; i<s.length(); i++){
            cumulative_shift += diff[i];
            int ascii_val = ((int)s[i]) + cumulative_shift;
            if(ascii_val<97){
                int val = (97 - ascii_val)%26;
                if(val == 0){
                    ascii_val = 97;
                }
                else{
                    ascii_val = 122 - val + 1;
                }
            }
            if(ascii_val>122){
                int val = (ascii_val-122)%26;
                if(val == 0){
                    ascii_val = 122;
                }
                else{
                    ascii_val = 97 + val - 1;
                }
            }
            s[i] = (char)ascii_val;
        }
        return s;
    }
};