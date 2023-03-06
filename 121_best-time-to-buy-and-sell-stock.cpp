/*
https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
maples1
3/5/2023
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // First idea: find the lowest value in the list, then 
        // the greatest value afterward? save the difference
        // if a higher value than the max is found, get the new
        // difference. If a lower value than the min is found,
        // use that for any further calculations

        int diff = 0, 
        min = prices[0], 
        max = prices[0],
        len = prices.size();

        for (int i = 0; i < len; i++)
        {
            if (prices[i] < min)
            {
                // set min to new low, 
                // reset max so that it does not
                // save a max from a past day
                min = prices[i];
                max = prices[i];
            } else if (prices[i] > max)
            {
                // if this is the highest difference so far, 
                // set it to current record of diff
                max = prices[i];
                if (diff < (max - min))
                {
                    diff = (max - min);
                }
            }
        }
        
        return diff;
    }
};