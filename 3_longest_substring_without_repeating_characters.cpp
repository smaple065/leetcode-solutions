/*
https://leetcode.com/problems/add-two-numbers/
maples1
5/22/2021
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // find longest substring without repeating characters
        // given strins s, return int lgst
        
        // for character, start creating a map and stop when one of the values hits 2
        // get length of map, save it as lgst if it's longer than previous
        int lgst = 0;
        map<char, int> charCt;
        int i, j, length = s.size(); // loop iterator and constraint
        
        // Iterate through characters in s
        for(i = 0; i < length; i++)
        {
            // Start creating a map of sequential characters in s, 
            // starting with character i
            for(j = i; j < length; j++)
            {
                // Add the character to the map if it does not already 
                // exist
                if (!charCt[s[j]]) 
                {
                    charCt[s[j]] = 1;
                }
                // Stop adding to map if the character does already exist
                else 
                {
                    break;
                }
                
                // Check the length of the current substring
                // Update longest if current substring is longer
                if (charCt.size() > lgst) lgst = charCt.size();
            }
            
            charCt.clear(); // clean slate for next iteration
        }
             
        // return the longest substring
        return lgst;
    }
};