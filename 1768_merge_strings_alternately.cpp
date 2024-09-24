/*
https://leetcode.com/problems/merge-strings-alternately/
maples1
9/24/2024
*/

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        // Solution: Iterate through both words in the same loop, checking if there are
        // letters remaining in each word and adding them if so. Add starting with word 1 so that
        // they alternate
        
        // Init empty string for result
        string res = "";
        // Get length of both words
        int word1Len = word1.size(), word2Len = word2.size();
        
        // Iterate through words
        int i = 0;
        while (i < word1Len || i < word2Len)
        {
            // If there are still letters left in either word, add them in alternation
            if(i < word1Len)
                res += word1[i];
            if(i < word2Len)
                res += word2[i];
            
            // iterate
            i++;
        }
        
        return res;
    }
};