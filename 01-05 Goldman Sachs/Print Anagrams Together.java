import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.List;

class Solution {
    public List<List<String>> Anagrams(String[] string_list) {
        // It Will return answer
        List<List<String>> groupedAnagrams = new ArrayList<>();
        
        // Map.... map<sorted_string, list<strings>>
        HashMap<String, List<String>> hmap = new HashMap<>();
        
        for(String str : string_list){
            
            // convert current string to characters array and sort it 
            // then make a string again with sorted charecters
            // then push current string on the sorted string key in map
            char[] characters = str.toCharArray();
            Arrays.sort(characters);
            String sorted = new String(characters);
            if(hmap.containsKey(sorted) == false){
                hmap.put(sorted, new ArrayList<>());
            }
            hmap.get(sorted).add(str);
        }
        
        // add all lists from map in ans
        groupedAnagrams.addAll(hmap.values());
        
        return groupedAnagrams;
    }
}