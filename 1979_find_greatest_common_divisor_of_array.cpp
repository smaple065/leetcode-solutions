/*
https://leetcode.com/problems/find-greatest-common-divisor-of-array/
maples1
7/13/2024
*/

class Solution {
public:
    int findGCD(vector<int>& nums) {
        /*Idea 1: iterate through the array and find the smallest number SmNum and largest number 
        LgNum, then check the remainder of both numbers when divided by every number counting down 
        from SmNum. The first number to have a remainder of zero is the largest common divisor.*/
        
        int smNum = nums[0], lgNum = nums[0]; // set largest and smallest to first elememt of nums
        int length = nums.size(); // count of elements in nums
        int gcd = 1; // greatest common denominator
        
        // Find the largest and smallest values in nums
        for (int i = 1; i < length; i++)
        {
            // set new high or low
            if (nums[i] > lgNum) lgNum = nums[i];
            if (nums[i] < smNum) smNum = nums[i];
        }
        
        // Starting at value of smNum, check if lgNum and smNum are divisible by i.
        // If neither are, move to the next largest number and check again
        for (int i = smNum; i > 1; i--)
        {
            // If the remainder of x/i is 0, x is divisible by i
            if ((0 == smNum%i) && (0 == lgNum%i))
            {
                return i;
            }
        }
        
        // Return one if no other common divisors were found
        return 1;
    }
};