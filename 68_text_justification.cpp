/*
https://leetcode.com/problems/text-justification/
maples1
6/8/2022
*/

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int i = 0, n = words.size();
        vector<string> justified;
        int avail = maxWidth;
        string line = "";
    
        // iterate through each word in words
        while (i < n)
        {
            int curLen = words[i].size();
            
            // if the current line is empty, add word without a space.
            if(line.empty())
            {
                line.append(words[i]);
                avail -= curLen;
                i++;
            }
            // if the current word fits in the current line, add it.
            // account for leading space
            else if (avail >= (curLen + 1))
            {
                line.append(" " + words[i]);
                avail -= (curLen +1);
                i++;
            }
            // otherwise, pad words with needed spacing in current line
            // and add to justified result
            else 
            {
                // fix spacing
                pad(line, maxWidth);
                justified.push_back(line);
                line = "";
                avail = maxWidth;
            }
            
            if (i == n) 
            {
                while(avail > 0)
                {
                    line.append(" ");
                    avail--;
                }
                justified.push_back(line);
            }
        }
        
        return justified;
    }
    
    void pad(string& str, int width)
    {
        cout << str << endl;
        // get number of spaces that needed to be added in order 
        // to achieve desired width
        int len = str.size();
        int padding = width - len;
        vector<int> spaceIndices;
        
        for (int i = 0; i < len; i++)
        {
            if(' ' == str[i]) spaceIndices.push_back(i);
        }
        
        // handle special case where only one word is present in this line
        int numSpaces = spaceIndices.size();
        if (0 == numSpaces)
        {
            while(padding > 0)
            {
                str.append(" ");
                padding--;
            }
            return;
        }
        
        // otherwise distribute spaces
        int toAdd = padding/numSpaces;
        int remainder = padding%numSpaces;
        
        // need an index buffer -- adding at index i from 
        // left to right will cause indices to shift, so every
        // time a char is added the buffer will increment
        int buffer = 0;
        
        for (int index : spaceIndices)
        {
            // number of spaces to add to the current slot
            // accounting for remainder if needed
            int n = toAdd;
            
            if (remainder > 0)
            {
                n += 1;
                remainder --;
            }
            
            str.insert(index+buffer, n, ' ');
            
            buffer+=n;
        }
        
        
    }
};