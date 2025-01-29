class Solution {
public:
    bool judgeCircle(string moves) {
        int vd= 0;
        int hd = 0;
        for(int i=0; i<moves.length(); i++){
            if(moves[i]=='U') vd++;
            else if(moves[i]=='D') vd--;
            else if(moves[i]=='R') hd++;
            else hd--;
        }
        if(vd==0 && hd==0) return true;
        return false;
    }
};