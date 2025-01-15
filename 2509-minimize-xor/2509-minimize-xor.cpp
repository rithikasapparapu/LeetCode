// class Solution {
// public:
//     string int2bin(int n){
//         string res = "";
//         while(n!=1){
//             res += to_string(n%2);
//             n=n/2;
//         }
//         res += "1";
//         reverse(res.begin(), res.end());
//         return res;
//     }

//     int bin2int(string s){
//         int n = s.length();
//         int res = 0;
//         int prod = 1;
//         for(int i=s.length()-1; i>=0; i--){
//             if(s[i]=='1'){
//                 res += prod;
//             }
//             prod = prod*2;
//         }
//         return res;
//     }
//     int minimizeXor(int num1, int num2) {
//         int count = 0;
//         while(num2!=1){
//             if(num2 % 2 != 0)
//                 count++;
//             num2 = num2 / 2;
//         }
//         count++;

//         string s1 = int2bin(num1);
//         string res = s1;

//         for(int i=0; i<s1.length()-1; i++){
//             if(s1[i]=='1'){
//                 if(count!=0){
//                     count--;
//                 }
//                 else{
//                     res[i] = '0';
//                 }
//             }
//         }
//         if(count == 0)
//             return bin2int(res);
//         for(int i=s1.length()-1; i>=0; i--){
//             if(count!=0){
//                 if(s1[i]=='0'){
//                     res[i] = '0';
//                     count--;
//                 }
//             }
//             else break;
//         }
//         if(count==0)
//             return bin2int(res);
//         reverse(res.begin(), res.end());
//         while(count!=0){
//             res += '1';
//             count--;
//         }
//         reverse(res.begin(), res.end());
//         return bin2int(res);
//     }
// };

class Solution {
public:
    string int2bin(int n) {
        if (n == 0) return "0";
        string res = "";
        while (n > 0) {
            res += to_string(n % 2);
            n = n / 2;
        }
        reverse(res.begin(), res.end());
        return res;
    }

    int bin2int(string s) {
        int res = 0;
        for (char c : s) {
            res = res * 2 + (c - '0');
        }
        return res;
    }

    int minimizeXor(int num1, int num2) {
        int count = __builtin_popcount(num2);
        string s1 = int2bin(num1);
        int len = s1.length();
        string res = s1;
        
        int ones_needed = count;
        for (int i = 0; i < len; i++) {
            if (s1[i] == '1' && ones_needed > 0) {
                ones_needed--;
                res[i] = '1';
            } else {
                res[i] = '0';
            }
        }
        
        if (ones_needed > 0) {
            for (int i = len - 1; i >= 0; i--) {
                if (ones_needed > 0 && res[i] == '0') {
                    res[i] = '1';
                    ones_needed--;
                }
                if (ones_needed == 0) break;
            }
        }

        while (ones_needed > 0) {
            res += '1';
            ones_needed--;
        }

        return bin2int(res);
    }
};
