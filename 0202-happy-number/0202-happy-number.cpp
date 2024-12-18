class Solution {
public:
    bool isHappy(int n) {
        unordered_map <int,int> map;
        bool result = true;
        int sum = n;
        while(sum!=1){
            int temp = sum;
            if(map.count(temp)==0){
                map[temp]++;
            }
            else
                return false;
            sum = 0;
            while(temp!=0){
                int remainder = temp%10;
                sum += remainder * remainder;
                temp = temp/10;
            }
        }
        return result;
    }
};