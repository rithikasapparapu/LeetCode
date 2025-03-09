class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int count = 0;
        for(int i=0; i<k; i++){
            if(blocks[i]=='W') count++;
        }
        int res = count;
        char prev = blocks[0];
        for(int i=1; i<blocks.size()-k+1; i++){
            if(prev == 'W') count--;
            if(blocks[i+k-1]=='W') count++;
            res = min(res, count);
            prev = (blocks[i]=='W') ? 'W' : 'B';
        }
        return res;
    }
};