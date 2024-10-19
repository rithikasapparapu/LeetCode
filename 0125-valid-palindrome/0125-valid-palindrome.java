class Solution {
    public boolean isAlphaNumeric(char character){
        if((character >= '0' && character <= '9') || (character >= 'A' && character <= 'Z') || (character >= 'a' && character <= 'z')){
            return true;
        }
        return false;
    }
    public boolean isPalindrome(String s) {
        s = s.toLowerCase();
        int l = 0;
        int r = s.length()-1;
        while(l<r){
            while(!isAlphaNumeric(s.charAt(l))){
                l++;
                if(l>=s.length()){
                    return true;
                }
            }
            while(!isAlphaNumeric(s.charAt(r))){
                r--;
            }
            if(s.charAt(l)!=s.charAt(r)){
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
}