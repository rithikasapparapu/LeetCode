class Solution {
    //two pointers approach is taking more time than the approach mentioned below.
    public boolean isSubsequence(String s, String t) {
        int l=0;
        int r=0;
        while(l<t.length() && r<s.length()){
            if(t.charAt(l)!=s.charAt(r)){
                l++;
            }
            else{
                l++;
                r++;
            }
        }
        if(r==s.length()){
            return true;
        }
        return false;
    }
}


/*
class Solution {
    public int isPresent(int index, char c, String s){
        int i=index+1;
        while(i<s.length()){
            if(c==s.charAt(i)){
                return i;
            }
            i++;
        }
        return -1;
    }
    public boolean isSubsequence(String s, String t) {
        int j=0;
        int index = -1;
        if(t.length()==0){
            if(s.length()==0){
                return true;
            } 
            return false;
        }
        if(t.length()==1){
            if(s.length()==0){
                return true;
            }
            if(s.length()==1 && s.charAt(0)==t.charAt(0)){
                return true;
            }
            return false;
        }
        while(j<s.length()){
            index = isPresent(index, s.charAt(j), t);
            if(index==-1){
                return false;
            }
            j++;
        }
        return true;
    }
}
*/