class Solution {
public:
    int mySqrt(int x) {
        if(x==1)
            return 1;
        for(long long i=1; i<x/2+1; i++){
            if(i*i<=x && (i+1)*(i+1)>x)
                return i;
        }
        return 0;
    }
};