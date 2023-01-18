/*
https://leetcode.com/problems/valid-mountain-array/
maples1
1/31/2022
*/

class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        bool peaked = 0;
        int len = arr.size();

        // if mountain is too small, return false
        if (len < 3)
        {
            return false;
        }
        
        for (int i = 0; i < (len-1); i++)
        {
             // if the mountain plateaus, return false
            if (arr[i] == arr[i+1])
            {
                return false;
            }
            // before the peak, the incline should be strictly increasing
  
            if (!peaked && (arr[i] > arr[i+1]))
            {
                // if there is no preceding incline, return false
                if (i == 0)
                {
                    return false;
                }
                // set peaked to true if the mountain begins to decrease
                peaked = true; 
            }
            
            // after the peak, the incline should be strictly descreasing
            // if the mountain peaked but there is an increase, return false
            else if (peaked && (arr[i] < arr[i+1]))
            {
                return false;
            }
        }
        
        // if the mountain never peaked, return false
        if (!peaked)
        {
            return false;
        }
        
        
        // return true by default
        return true;
    }
};