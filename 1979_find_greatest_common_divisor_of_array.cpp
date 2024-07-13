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
        
        /*Idea 2: Skip the first loop in favor of calling a simple sort function on nums, then grab the first and 
        last element to serve as the largest and smallest numbers*/
        
        int length = nums.size(); // count of elements in nums
        int gcd = 1; // greatest common denominator
        
        sort(nums.begin(), nums.end());
        int smNum = nums[0], lgNum = nums[nums.size()-1];
        
        cout << "Smallest: " << smNum << " Largest: " << lgNum;
        
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