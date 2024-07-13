/*
https://leetcode.com/problems/remove-duplicates-from-sorted-array/
maples1
7/12/2024
*/
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        /* Idea #1: 
        starting at the second element of nums, compare the current
        element to the previous element. If they are the same, remove the
        current element. If not, add 1 to the number of unique values.
        */
        
        int k = 1; // Number of unique values in nums 
        int cur = nums[0]; // first element in nums
        int len = nums.size(); // length of nums
        int numDupes = 0; // count duplicate elements
        
        // iterate through nums
        for(int i = 1; i < len; i++)
        {
            if (nums[i] == cur)
            {
                cout << "Deleting nums[" << i << "] Value " << nums[i] << endl;
                nums.erase(nums.begin()+i); // erase at index i

                // adust length of nums and current index since a deletion shifted everything left by one
                i--;
                len--;
            }
            // if element is unique
            else
            {
                cout << "Keeping nums[" << i << "] Value " << nums[i] << endl;
                // add to # of unique elements
                k++;
                // Set prior element to value of current element
                cur = nums[i];
            }
        }
        
        cout << "nums: ";
        for (auto i :nums)
        {
            cout << i <<" ";
        }
        cout << endl << "k: " << k;
        return k;   
    }
};