class Solution {
    public int lengthOfLongestSubstring(String s) {
        HashSet<Character> elements = new HashSet<>();
        int i=0;
        int j=0;
        // if(s.length()==0){
        //     return 0;
        // }
        // if(s.length()==1){
        //     return 1;
        // }
        int count = Integer.MIN_VALUE;
        while(j<s.length()){
            if(!elements.contains(s.charAt(j))){
                elements.add(s.charAt(j));
                j++;
            }
            else{
                if(count < j-i){
                    count = j-i;
                }
                elements.remove(s.charAt(i));
                i++;
            }
        }
        if(count < j-i){
            count = j-i;
        }
        return count;
    }
}