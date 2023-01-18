/*
https://leetcode.com/problems/bulls-and-cows/
maples1
6/5/2022
*/

class Solution {
public:
    string getHint(string secret, string guess) {
        int n = secret.size();
        int bulls = 0, cows = 0;
        int i = 0;
        // char counts for the secret and guess
        map<char, int> secretCh, guessCh;
        
        // get number of bulls
        for (int i = 0; i < n; i++)
        {
            if (secret[i] == guess[i])
                bulls++;
            // if it's not a bull, it still could be a cow
            else 
            {
                // Add character count from each string to the corresponding map
                if (!secretCh[secret[i]])
                    secretCh[secret[i]] = 1;
                else
                    secretCh[secret[i]]++;
                
                if (!guessCh[guess[i]])
                    guessCh[guess[i]] = 1;
                else
                    guessCh[guess[i]]++;
            }
        }
        
        // iterate through remaining characters to count up cows
        while(i != 10)
        {
            char j = '0' + i; // char value of i 
            
            cout << j << " " << secretCh[j] << " " << guessCh[j] << endl;
            if (secretCh[j] > 0 && guessCh[j] > 0)
            {
                cows++;
                secretCh[j]--;
                guessCh[j]--;
            }
            else 
                i++;
        } 
        
        return (to_string(bulls) + "A" + to_string(cows) + "B");
        
    }
};