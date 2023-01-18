/*
https://leetcode.com/problems/longest-common-prefix/
maples1
5/28/2022
*/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string longestPrefix = ""; // string to store the longest prefix
        bool broken = false;    // true when the prefix has been found
        int i= 0;               // iterator
        char cur;               // current character in string
        
        while(!broken)
        {
            if (!strs[0][i])
            {
                break;
            }
            else 
            {
                // get next character of first string
                cur = strs[0][i];
                
                // make sure all strings share that character in place
                for (string str : strs)
                {
                    // if there is variation, break and declare 
                    // the prefix broken
                    if (str[i] != cur)
                    {
                        broken = true;
                        break;
                    }
                }
                // Add cur to longest prefix if unbroken
                if (!broken) longestPrefix.push_back(cur);
            }
            
            i++;
        }
        
        return longestPrefix;
    }
};