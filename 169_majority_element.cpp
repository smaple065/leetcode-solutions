/*
https://leetcode.com/problems/majority-element/
maples1
1/17/2023
*/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        /*
        Count number of times that each number occurs in the list
        As soon as a count greater then n/2 is reached, return the
        number that said count belongs to
        */

        int n = nums.size();
        int threshold = floor(n/2);
        map<int,int> cts;

        // Count each value and add it to a map
        for (auto num : nums)
        {
            // set to 1 if this is the first instance of this value
            if (!cts[num])
                cts[num] = 1;
            // otherwise increment count
            else 
                cts[num]++;

            // return value if its count exceeds the threshold
            if (cts[num] > threshold)
                return num; 
        }

        // Assuming there is always a solution, this
        // should never be hit
        return -1;
    }
};