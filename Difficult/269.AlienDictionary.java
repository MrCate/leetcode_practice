class Solution {
    public String alienOrder(String[] words) {
        Map<Character, Set<Character>> map = new HashMap<>();
        for(int i=0;i<words.length -1;i++){
            for(int j =0;j<words[i].length() && j<words[i+1].length();j++){
                if(words[i].charAt(j)==words[i+1].charAt(j))
                    continue;
                Set<Character> set = map.getOrDefault(words[i].charAt(j), new HashSet<>());
                set.add(words[i+1].charAt(j));
                map.put(words[i].charAt(j), set);
                break;
            }                         
        }
        int[] degrees = new int[26];
        Arrays.fill(degrees,-1);
        for(String str: words){
            for(char c: str.toCharArray())
                degrees[c-'a'] = 0;
        }
        for(char key : map.keySet()){
            for(char val:map.get(key)){
                degrees[val-'a']++;
            }
        }
        StringBuilder sb = new StringBuilder();
        Queue<Character> list = new LinkedList<>();
        int count = 0;
        for(int i=0;i<26;i++){
            if(degrees[i]!=-1)
                count++;
            if(degrees[i]==0){
                list.add((char)('a'+i));
            }
        }
        while(!list.isEmpty()){
            Character cur = list.poll();
            sb.append(cur);
            if(map.containsKey(cur)){
                Set<Character> set = map.get(cur);
                for(Character c:set){
                    degrees[c-'a']--;
                    if(degrees[c-'a']==0)
                        list.add(c);
                }
            }
        }
        if(sb.length()!=count)
            return "";
        else
            return sb.toString();
    }
}