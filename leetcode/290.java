class Solution {
    public boolean wordPattern(String pattern, String s) {
        String[] words = s.split(" ");
        if(words.length != pattern.length()) return false;
        HashMap<Character, String> map = new HashMap<Character, String>();
        for(int i = 0; i < words.length; i++) {
            char p = pattern.charAt(i);
            if(map.containsKey(p)) {
                if(!map.get(p).equals(words[i])) return false;
            }
            else {
                if(map.containsValue(words[i])) return false;
                map.put(p, words[i]);
            }
        } 
        return true;
    }
}