/*
https://leetcode.com/problems/camelcase-matching/
maples1
12/13/2021
*/

class Solution {
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        vector<bool> result;
        bool match;
        // iterator for characters in pattern
        int cur, pLen = pattern.size();
        
        cout << pattern << endl;
        
        // Iterate through queries
        for (auto query : queries)
        {
            // set defaults
            cur = 0;
            match = false;
            int max = query.size();
            
            // Analyze characters from query and compare to pattern
            for (auto ch : query)
            {
                // if character is expected from pattern
                if (ch == pattern[cur])
                {
                    cur++;
                    // if entire pattern has been satisfied
                    if(cur == pLen)
                    {
                        match = true;
                    }
                }
                // if an unexpected capital letter is met
                else if (int(ch) < 97)
                {
                    match = false;
                    break;
                }
            }
            // add result to list
            result.push_back(match);
        }
        return result;
    }
};