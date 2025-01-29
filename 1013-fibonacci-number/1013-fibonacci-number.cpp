class Solution {
public:
    int fib(int n) {
        if(n==0) return 0;
        int last = 0;
        int prev = 1;
        int temp;
        for(int i=2; i<=n; i++){
            temp = prev;
            prev = prev + last;
            last = temp;
        }
        return prev;
    }
};