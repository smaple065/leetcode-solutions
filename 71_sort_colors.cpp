/*
https://leetcode.com/problems/sort-colors/
maples1
3/16/2023
*/

class Solution {
public:
    void sortColors(vector<int>& nums) {
        /*
        Idea: keep a count of each color and overwrite the original
        vector with sorted values
        */

        // keep track of color counts
        vector<int> colorCts = {0,0,0};

        // loop through nums and count colors
        for (auto color : nums)
        {
            switch(color)
            {
                // red
                case 0: 
                    colorCts[0]++;
                    break;
                // white
                case 1:
                    colorCts[1]++;
                    break;
                // blue
                default:
                    colorCts[2]++;
            }
        }

        // For each count of a color, overwrite position i of
        // nums with that color
        int i = 0; 
        while ((0 != colorCts[0]) || (0 != colorCts[1]) || (0 != colorCts[2]))
        {
            // if there are still reds,
            // add red to nums and decrement 
            // remaining reds
            if (0 != colorCts[0])
            {
                nums[i] = 0;
                colorCts[0]--;
            }
            // if there are still whites
            else if(0 != colorCts[1])
            {
                nums[i] = 1;
                colorCts[1]--;
            }
            // if there are still blues
            else if(0 != colorCts[2])
            {
                nums[i] = 2;
                colorCts[2]--;
            }
            // move to next position in nums
            i++;
        }       
    }
};