class Solution {
public:
    int maxScore(string s) {
        int left_sum = 0;
        if(s[0]=='0'){
            left_sum = 1;
        }
        int right_sum = 0;
        for(int i=1; i<s.length(); i++){
            right_sum += stoi(s.substr(i,1));
        }
        int max = left_sum + right_sum;
        for(int i=1; i<s.length()-1; i++){
            if(s[i]=='1'){
                right_sum -= 1;
            }
            else{
                left_sum += 1;
            }
            if(max < left_sum + right_sum){
                max = left_sum + right_sum;
            }
        }
        return max;
    }
};